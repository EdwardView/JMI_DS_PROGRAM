//TOken select in the expression

#include<iostream>
#include<string>
using namespace std;
class NODE{
public :
    char ch;
    NODE *next;
    NODE()
    {next = NULL;}
};
class Token{
    NODE * first;
    public :
            Token(){first = NULL;}
            void StringToken(string s);
            void display();
};
void Token :: StringToken(string s){
           int i=0;
           while(s[i] != '\0'){
                if(s[i] != ' '){
                    NODE *nn = new NODE;
                    nn->ch = s[i];
                    if(first == NULL)
                            first = nn;
                    else{
                            NODE *temp = first;
                            while(temp->next != NULL){
                            temp = temp->next;
                            }
                            temp->next = nn;
                    }
                }
                i++;
           }
}
void Token :: display(){
    NODE *temp = first;
    while(temp != NULL){
        cout << temp->ch << " ";
        temp = temp->next;
    }
}
int main(){
    string str = "( ( 10 - 12 ) + 12 )";
    Token t1;
    t1.StringToken(str);
    t1.display();

}
