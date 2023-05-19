// Discrete_Math.cpp

#include <vector>
#include <sstream>
#include <iostream>
#include <cstdlib>

using namespace std;

string vec_to_string(vector<int> vec){
    ostringstream os;
    os<<"{";
    for(size_t i=0;i<vec.size();i++){
        os<<vec[i];
        if(i!=vec.size()-1){
            os<<",";
        }
    }
    os<<"}";
    return os.str();
}

int main(int argc, char **argv){

    bool is_valid=false;
    string quantifier1 ="u";
    string quantifier2 ="e";

    if(argc>0){
        istringstream(argv[1]) >> quantifier1;
        istringstream(argv[2]) >> quantifier2;
    }

    int ints1[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int ints2[]={3,5,15};

    vector<int> x(ints1, ints1 + sizeof(ints1) / sizeof(int) );
    vector<int> y(ints2, ints2 + sizeof(ints2) / sizeof(int) );

    
    cout<<"X: "<<vec_to_string(x)<<endl;
    cout<<"Y: "<<vec_to_string(y)<<endl;


    if(quantifier1=="u" && quantifier2=="e"){
        cout<<endl<<"For all n in X, there is some m in Y where n * m >= 15"<<endl<<endl;
        for(size_t i=0;i<x.size();i++){
            cout<<"X: n is "<<x[i]<<endl;
            for(size_t j=0;j<y.size();j++){
                cout<<"   Y: m is "<<y[j];
                if(x[i]*y[j] >= 15){
                    cout<<" and is valid."<<endl;
                    is_valid=true;
                    break;
                }
                else{
                    cout<<" and is invalid."<<endl;
                    is_valid=false;
                }
            }
            if(!is_valid){
                cout<<endl<<"This statement is INVALID."<<endl;
                break;
            }
        }
        if(is_valid){
            cout<<endl<<"This statement is VALID."<<endl;
        }
    }

    if(quantifier1=="e" && quantifier2=="u"){
        cout<<"For some n in X, there is all m in Y where n/m is an integer"<<endl<<endl;
        for(size_t i=0;i<x.size();i++){
            cout<<"X: n is "<<x[i]<<endl;
            for(size_t j=0;j<y.size();j++){
                cout<<"   Y: m is "<<y[j];
                if(x[i]%y[j] == 0){
                    cout<<" and is valid."<<endl;
                    is_valid=true;
                }
                else{
                    cout<<" and is invalid."<<endl;
                    is_valid=false;
                    break;
                }
            }
            if(is_valid){
                cout<<endl<<"This statement is VALID."<<endl;
                break;
            }
        }
        if(!is_valid){
            cout<<endl<<"This statement is INVALID."<<endl;           
        }
    }

    if(quantifier1=="u" && quantifier2=="u"){
        cout<<"For all n in X, there is all m in Y where m*n >= 2"<<endl<<endl;
        for(size_t i=0;i<x.size();i++){
            cout<<"X: n is "<<x[i]<<endl;
            for(size_t j=0;j<y.size();j++){
                cout<<"   Y: m is "<<y[j];
                if(x[i]*y[j] >= 2){
                    cout<<" and is valid."<<endl;
                    is_valid=true;
                }
                else{
                    cout<<" and is invalid."<<endl;
                    is_valid=false;
                    cout<<endl<<"This statement is INVALID."<<endl;
                    return 0; // exit both loops
                }
            }
        }
        if(is_valid){
            cout<<endl<<"This statement is VALID."<<endl;           
        }
    }

    if(quantifier1=="e" && quantifier2=="e"){
        cout<<"For some n in X, there is some m in Y where m*n >= 10"<<endl<<endl;
        for(size_t i=0;i<x.size();i++){
            cout<<"X: n is "<<x[i]<<endl;
            for(size_t j=0;j<y.size();j++){
                cout<<"   Y: m is "<<y[j];
                if(x[i]*y[j] >= 10){
                    cout<<" and is valid."<<endl;
                    is_valid=true;
                    cout<<endl<<"This statement is VALID."<<endl;
                    return 0; // exit both loops
                }
                else{
                    cout<<" and is invalid."<<endl;
                    is_valid=false;

                }
            }
        }
        if(!is_valid){
            cout<<endl<<"This statement is INVALID."<<endl;           
        }
    }

    return 0;

}

