#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>


using namespace std;

struct Rule{
    string l;
    string r; 
    Rule(const string& left, const string& right) : l(left), r(right) {}
};


vector<Rule> allRulesT2;

string alphabet = "ab";


void initRulesT2(){
    allRulesT2.push_back(Rule("aaaa", "a"));
    allRulesT2.push_back(Rule("aaab", "b"));
    allRulesT2.push_back(Rule("bbaaa", "baab"));
    allRulesT2.push_back(Rule("bbaab", "baa"));
    allRulesT2.push_back(Rule("bbabb", "abab"));
    allRulesT2.push_back(Rule("babbaa", "babba"));
    allRulesT2.push_back(Rule("babbab", "abb"));
    allRulesT2.push_back(Rule("bab", "abb"));
    allRulesT2.push_back(Rule("baa", "abb"));
    allRulesT2.push_back(Rule("abb", "bb"));
    allRulesT2.push_back(Rule("bba", "bb"));
    allRulesT2.push_back(Rule("bb", "ba"));
    allRulesT2.push_back(Rule("aba", "ba"));
}

// l - левая граница подстроки в s (индекс), которую нужно заменить по правилу
void executeRule(Rule rule, string& s, int l){
    //string& replace (size_t pos, size_t len, const string& str);
    int len = rule.l.length();
    s.replace(l, len, rule.r);
}

//проверим, можно ли применить правило из списка Rules
pair<bool, int> checkIsRuleMayBeApplied(Rule rule, const string& s){
    pair<bool, int> p;
    size_t found = s.find(rule.l);
    p.second = found;

    if (found != std::string::npos) {
        p.first = true;
        return p;
    }
    
    p.first = false;
    return p;
}


//генерация случайного номера правила в системе T2
// n - сколько всего правил
int getRandomRuleT2(int n) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<int> dist(0, n - 1);
    return dist(gen);
}

//генерация случайной строки, заданной длины n, состоящей из символов 
//фиксированного алфавита
string getRandomString(int n, const string& alphabet) {
    string s;
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<int> dist(0, alphabet.size() - 1);
    for (int i = 0; i < n; i++){
        s += alphabet[dist(gen)];
    }
    return s;
}


pair<bool, pair<string, vector<int>>> fuzzing(){
    pair<bool, pair<string, vector<int>>> p1;
    p1.first = true;
    p1.second.first = "";
    vector<int> emptyVector;
    p1.second.second = emptyVector;
    for (int i = 0; i < 50000; i++){
        string s = getRandomString(15, alphabet);
        
    }
    return p1;
}

int main(){
    initRulesT2();
    pair<bool, pair<string, vector<int>>> p = fuzzing();
    if (p.first){
        cout << "все тесты успешны" << endl;
    }
}