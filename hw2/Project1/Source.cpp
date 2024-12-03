#include <iostream>
#include <sstream>  // ¥Î©ó stringstream
#include <algorithm>
using namespace std;
struct term {
    float coef;
    int exp;
    term(float c = 0.0, int e = 0) : coef(c), exp(e) {}
};
class polynomial {
private:
    term* terms;  // °ÊºA°}¦CÀx¦s¶µ¥Ø
    int numterms;
    int capacity;
    void resize(int newCapacity);
public:
    polynomial(int initialCapacity = 10);
    ~polynomial();
    void newterm(float coef, int exp);
<<<<<<< HEAD
=======
    float Eval(float x) const; // ·s¼W Eval ¨ç¼Æ
>>>>>>> 9267a73 (æœ€å¾Œç„¡æ³•ç›¸åŠ ç›¸ä¹˜)
    friend ostream& operator<<(ostream& os, const polynomial& poly);
    friend istream& operator>>(istream& is, polynomial& poly);
    polynomial operator+(const polynomial& other) const;
    polynomial operator*(const polynomial& other) const;
};
<<<<<<< HEAD
=======
float polynomial::Eval(float x) const {
    float result = 0;
    for (int i = 0; i < numterms; ++i) {
        result += terms[i].coef * pow(x, terms[i].exp); // ­pºâ¨C­Ó¶µ¥Ø
    }
    return result;
}
>>>>>>> 9267a73 (æœ€å¾Œç„¡æ³•ç›¸åŠ ç›¸ä¹˜)
polynomial::polynomial(int initialCapacity) : numterms(0), capacity(initialCapacity) {
    terms = new term[capacity];
}
polynomial::~polynomial() {
<<<<<<< HEAD
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
        if (terms[i].exp == exp) {  // ÀË¬d¬O§_¤w¦s¦b¬Û¦P«ü¼Æªº¶µ
            terms[i].coef += coef;
            if (terms[i].coef == 0) {  // ­Y¬Û¥[«á«Y¼Æ¬° 0¡A²¾°£
=======
    if (terms) { // ½T«O«ü¼Ð«DªÅ
        delete[] terms;
        terms = nullptr; // Á×§K­«½ÆÄÀ©ñ
    }
}
void polynomial::resize(int newCapacity) {
    term* newterms = new term[newCapacity]; // ¤À°t·s°}¦C
    for (int i = 0; i < numterms; ++i) {
        newterms[i] = terms[i]; // ½Æ»s²{¦³¼Æ¾Ú
    }
    delete[] terms; // ÄÀ©ñÂÂ°}¦C
    terms = newterms; // §ó·s«ü¼Ð
    capacity = newCapacity; // §ó·s®e¶q
}
void polynomial::newterm(float coef, int exp) {
    if (coef == 0) return; // ©¿²¤«Y¼Æ¬° 0 ªº¶µ
    for (int i = 0; i < numterms; ++i) {
        if (terms[i].exp == exp) { // ¦pªG¤w¦³¬Û¦P«ü¼Æ¡A¦X¨Ö«Y¼Æ
            terms[i].coef += coef;
            if (terms[i].coef == 0) { // ¦pªG«Y¼ÆÅÜ¬° 0¡A²¾°£¸Ó¶µ
>>>>>>> 9267a73 (æœ€å¾Œç„¡æ³•ç›¸åŠ ç›¸ä¹˜)
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
<<<<<<< HEAD
        return a.exp > b.exp;
=======
        return a.exp > b.exp; // «ö«ü¼Æ­°§Ç±Æ§Ç
>>>>>>> 9267a73 (æœ€å¾Œç„¡æ³•ç›¸åŠ ç›¸ä¹˜)
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
        cout << "¿é¤J«Y¼Æ©M«ü¼Æ,¦pªG¤£·Q¿é¤J½Ð¿é¤J(q q): " << endl;
        ist >> coef_input >> exp_input;
        if ((coef_input == "q" || coef_input == "Q") && (exp_input == "q" || exp_input == "Q")) {
            break;
        }
        stringstream ss_coef(coef_input), ss_exp(exp_input); // ±N«Y¼Æ©M«ü¼ÆÂà´«¬°¼Æ¦r
        float coef;
        int exp;
        if (!(ss_coef >> coef) || !(ss_exp >> exp)) {
            cout << "µL®Äªº¿é¤J¡A½Ð­«·s¿é¤J¦³®Äªº«Y¼Æ»P«ü¼Æ¡C" << endl;
            continue;  // ¦pªG¿é¤JµL®Ä¡A«hÄ~Äò´`Àô
        }
        poly.newterm(coef, exp);  // ·s¼W¦h¶µ¦¡¶µ¥Ø
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
<<<<<<< HEAD
=======

>>>>>>> 9267a73 (æœ€å¾Œç„¡æ³•ç›¸åŠ ç›¸ä¹˜)
    for (int i = 0; i < numterms; ++i) {
        for (int j = 0; j < other.numterms; ++j) {
            float coef = terms[i].coef * other.terms[j].coef;
            int exp = terms[i].exp + other.terms[j].exp;
<<<<<<< HEAD
            result.newterm(coef, exp);
=======
            result.newterm(coef, exp); 
>>>>>>> 9267a73 (æœ€å¾Œç„¡æ³•ç›¸åŠ ç›¸ä¹˜)
        }
    }
    return result;
}
<<<<<<< HEAD
=======

>>>>>>> 9267a73 (æœ€å¾Œç„¡æ³•ç›¸åŠ ç›¸ä¹˜)
int main(void) {
    polynomial p1, p2;
    int choice;
    cout << "½Ð¿é¤J²Ä¤@­Ó¦h¶µ¦¡:" << endl;
    cin >> p1;
    cout << "±z¿é¤Jªº²Ä¤@­Ó¦h¶µ¦¡¬O: " << p1 << endl;
    cout << "½Ð¿é¤J²Ä¤G­Ó¦h¶µ¦¡:" << endl;
    cin >> p2;
    cout << "±z¿é¤Jªº²Ä¤G­Ó¦h¶µ¦¡¬O: " << p2 << endl;
    cout << "½Ð¿ï¾Ü¹Bºâ¤è¦¡:" << endl;
    cout << "1. ¥[ªk (+)" << endl;
    cout << "2. ­¼ªk (*)" << endl;
    cout << "½Ð¿é¤J±zªº¿ï¾Ü: ";
    cin >> choice;
    polynomial result;
    if (choice == 1) {
        result = p1 + p2;
        cout << "¥[ªkµ²ªG: " << result << endl;
    }
    else if (choice == 2) {
        result = p1 * p2;
        cout << "­¼ªkµ²ªG: " << result << endl;
    }
    return 0;
}
