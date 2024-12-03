#include <iostream>
#include <sstream>  // �Ω� stringstream
#include <algorithm>
using namespace std;
struct term {
    float coef;
    int exp;
    term(float c = 0.0, int e = 0) : coef(c), exp(e) {}
};
class polynomial {
private:
    term* terms;  // �ʺA�}�C�x�s����
    int numterms;
    int capacity;
    void resize(int newCapacity);
public:
    polynomial(int initialCapacity = 10);
    ~polynomial();
    void newterm(float coef, int exp);
<<<<<<< HEAD
=======
    float Eval(float x) const; // �s�W Eval ���
>>>>>>> 9267a73 (最後無法相加相乘)
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
        result += terms[i].coef * pow(x, terms[i].exp); // �p��C�Ӷ���
    }
    return result;
}
>>>>>>> 9267a73 (最後無法相加相乘)
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
        if (terms[i].exp == exp) {  // �ˬd�O�_�w�s�b�ۦP���ƪ���
            terms[i].coef += coef;
            if (terms[i].coef == 0) {  // �Y�ۥ[��Y�Ƭ� 0�A����
=======
    if (terms) { // �T�O���ЫD��
        delete[] terms;
        terms = nullptr; // �קK��������
    }
}
void polynomial::resize(int newCapacity) {
    term* newterms = new term[newCapacity]; // ���t�s�}�C
    for (int i = 0; i < numterms; ++i) {
        newterms[i] = terms[i]; // �ƻs�{���ƾ�
    }
    delete[] terms; // �����°}�C
    terms = newterms; // ��s����
    capacity = newCapacity; // ��s�e�q
}
void polynomial::newterm(float coef, int exp) {
    if (coef == 0) return; // �����Y�Ƭ� 0 ����
    for (int i = 0; i < numterms; ++i) {
        if (terms[i].exp == exp) { // �p�G�w���ۦP���ơA�X�֫Y��
            terms[i].coef += coef;
            if (terms[i].coef == 0) { // �p�G�Y���ܬ� 0�A�����Ӷ�
>>>>>>> 9267a73 (最後無法相加相乘)
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
        return a.exp > b.exp; // �����ƭ��ǱƧ�
>>>>>>> 9267a73 (最後無法相加相乘)
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
        cout << "��J�Y�ƩM����,�p�G���Q��J�п�J(q q): " << endl;
        ist >> coef_input >> exp_input;
        if ((coef_input == "q" || coef_input == "Q") && (exp_input == "q" || exp_input == "Q")) {
            break;
        }
        stringstream ss_coef(coef_input), ss_exp(exp_input); // �N�Y�ƩM�����ഫ���Ʀr
        float coef;
        int exp;
        if (!(ss_coef >> coef) || !(ss_exp >> exp)) {
            cout << "�L�Ī���J�A�Э��s��J���Ī��Y�ƻP���ơC" << endl;
            continue;  // �p�G��J�L�ġA�h�~��`��
        }
        poly.newterm(coef, exp);  // �s�W�h��������
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

>>>>>>> 9267a73 (最後無法相加相乘)
    for (int i = 0; i < numterms; ++i) {
        for (int j = 0; j < other.numterms; ++j) {
            float coef = terms[i].coef * other.terms[j].coef;
            int exp = terms[i].exp + other.terms[j].exp;
<<<<<<< HEAD
            result.newterm(coef, exp);
=======
            result.newterm(coef, exp); 
>>>>>>> 9267a73 (最後無法相加相乘)
        }
    }
    return result;
}
<<<<<<< HEAD
=======

>>>>>>> 9267a73 (最後無法相加相乘)
int main(void) {
    polynomial p1, p2;
    int choice;
    cout << "�п�J�Ĥ@�Ӧh����:" << endl;
    cin >> p1;
    cout << "�z��J���Ĥ@�Ӧh�����O: " << p1 << endl;
    cout << "�п�J�ĤG�Ӧh����:" << endl;
    cin >> p2;
    cout << "�z��J���ĤG�Ӧh�����O: " << p2 << endl;
    cout << "�п�ܹB��覡:" << endl;
    cout << "1. �[�k (+)" << endl;
    cout << "2. ���k (*)" << endl;
    cout << "�п�J�z�����: ";
    cin >> choice;
    polynomial result;
    if (choice == 1) {
        result = p1 + p2;
        cout << "�[�k���G: " << result << endl;
    }
    else if (choice == 2) {
        result = p1 * p2;
        cout << "���k���G: " << result << endl;
    }
    return 0;
}
