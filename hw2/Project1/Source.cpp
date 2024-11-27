#include <iostream>
#include <sstream>  // 用於 stringstream
#include <algorithm>
using namespace std;
struct term {
    float coef;
    int exp;
    term(float c = 0.0, int e = 0) : coef(c), exp(e) {}
};
class polynomial {
private:
    term* terms;  // 動態陣列儲存項目
    int numterms;
    int capacity;
    void resize(int newCapacity);
public:
    polynomial(int initialCapacity = 10);
    ~polynomial();
    void newterm(float coef, int exp);
    friend ostream& operator<<(ostream& os, const polynomial& poly);
    friend istream& operator>>(istream& is, polynomial& poly);
    polynomial operator+(const polynomial& other) const;
    polynomial operator*(const polynomial& other) const;
};
polynomial::polynomial(int initialCapacity) : numterms(0), capacity(initialCapacity) {
    terms = new term[capacity];
}
polynomial::~polynomial() {
    delete[] terms;
}
void polynomial::resize(int newCapacity) {
    term* newterms = new term[newCapacity];
    for (int i = 0; i < numterms; ++i) {
        newterms[i] = terms[i];
    }
    delete[] terms;
    terms = newterms;
    capacity = newCapacity;
}
void polynomial::newterm(float coef, int exp) {
    if (coef == 0) return;
    for (int i = 0; i < numterms; ++i) {
        if (terms[i].exp == exp) {  // 檢查是否已存在相同指數的項
            terms[i].coef += coef;
            if (terms[i].coef == 0) {  // 若相加後係數為 0，移除
                for (int j = i; j < numterms - 1; ++j) {
                    terms[j] = terms[j + 1];
                }
                numterms--;
            }
            return;
        }
    }
    if (numterms == capacity) {
        resize(capacity * 2);
    }
    terms[numterms++] = term(coef, exp);
    sort(terms, terms + numterms, [](const term& a, const term& b) {
        return a.exp > b.exp;
        });
}
ostream& operator<<(ostream& ost, const polynomial& poly) {
    if (poly.numterms == 0) {
        ost << "0";
        return ost;
    }
    for (int i = 0; i < poly.numterms; ++i) {
        if (i > 0 && poly.terms[i].coef > 0) ost << " + ";
        ost << poly.terms[i].coef << "x^" << poly.terms[i].exp;
    }
    return ost;
}
istream& operator>>(istream& ist, polynomial& poly) {
    while (true) {
        string coef_input, exp_input;
        cout << "輸入係數和指數,如果不想輸入請輸入(q q): " << endl;
        ist >> coef_input >> exp_input;
        if ((coef_input == "q" || coef_input == "Q") && (exp_input == "q" || exp_input == "Q")) {
            break;
        }
        stringstream ss_coef(coef_input), ss_exp(exp_input); // 將係數和指數轉換為數字
        float coef;
        int exp;
        if (!(ss_coef >> coef) || !(ss_exp >> exp)) {
            cout << "無效的輸入，請重新輸入有效的係數與指數。" << endl;
            continue;  // 如果輸入無效，則繼續循環
        }
        poly.newterm(coef, exp);  // 新增多項式項目
    }
    return ist;
}
polynomial polynomial::operator+(const polynomial& other) const {
    polynomial result;
    for (int i = 0; i < numterms; ++i) {
        result.newterm(terms[i].coef, terms[i].exp);
    }
    for (int i = 0; i < other.numterms; ++i) {
        result.newterm(other.terms[i].coef, other.terms[i].exp);
    }
    return result;
}
polynomial polynomial::operator*(const polynomial& other) const {
    polynomial result;
    for (int i = 0; i < numterms; ++i) {
        for (int j = 0; j < other.numterms; ++j) {
            float coef = terms[i].coef * other.terms[j].coef;
            int exp = terms[i].exp + other.terms[j].exp;
            result.newterm(coef, exp);
        }
    }
    return result;
}
int main(void) {
    polynomial p1, p2;
    int choice;
    cout << "請輸入第一個多項式:" << endl;
    cin >> p1;
    cout << "您輸入的第一個多項式是: " << p1 << endl;
    cout << "請輸入第二個多項式:" << endl;
    cin >> p2;
    cout << "您輸入的第二個多項式是: " << p2 << endl;
    cout << "請選擇運算方式:" << endl;
    cout << "1. 加法 (+)" << endl;
    cout << "2. 乘法 (*)" << endl;
    cout << "請輸入您的選擇: ";
    cin >> choice;
    polynomial result;
    if (choice == 1) {
        result = p1 + p2;
        cout << "加法結果: " << result << endl;
    }
    else if (choice == 2) {
        result = p1 * p2;
        cout << "乘法結果: " << result << endl;
    }
    return 0;
}
