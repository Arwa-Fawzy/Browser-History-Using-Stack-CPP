//the time complexity of this code is O(N) time.

#include <bits/stdc++.h>
//standard library that includes all of c++ libraries
using namespace std;


class BrowserHistory{
    public:
    stack<string> s1;
    stack<string> s2;
    // creating two stacks as going forward to many pages will push links into s1
    //while going back to the former pages will pop the links from s1 and add it to s2

    BrowserHistory(string homepage){ //home page is the first page the user enters
        while (!s1.empty()){ // the first step is to remove all the elements in the stack
            s1.pop(); // to place the first page the user enters the homepage
        }
        while (!s2.empty()){
            s2.pop();
        }
        s1.push(homepage);
    }
    void visit(string url){
        s1.push(url); //if you visit a new page, the link of this page will be pushed to s1
        while (!s2.empty()){ //if there is a page in s2 it will be removed from memory
            s2.pop();
        }
    }
    string back(int steps){
        while (steps-- && s1.size()>1){  //keeping at least one element in the stack to be removed
            s2.push(s1.top()); // going back means removing the top of s1 and saving it in s2 memory
            s1.pop();
        }
        return s1.top(); // displaying the current page that the browser shows
    }
    string forward(int steps){
        while (steps-- && !s2.empty()){
            s1.push(s2.top()); // going forward means adding the top of s2 and removing it from s2 memory
            s2.pop();
        }
        return s1.top(); // displaying the current page that the browser shows
    }
};

int main(){
     // it is time to call the functions
    BrowserHistory bh = BrowserHistory("abc.com"); //creating object from the class called bh
    bh.visit("xyz.com"); //visit function does not return anything so there is no displaying, just call it
    bh.visit("def.com");
    bh.visit("ijk.com");
    cout<<bh.back(1)<<endl;
    cout<<bh.back(1)<<endl;
    cout<<bh.forward(1)<<endl;
    bh.visit("mno.com");
    cout<<bh.forward(2)<< endl;
    cout<<bh.back(2)<<endl;
    cout<<bh.back(7);
}
