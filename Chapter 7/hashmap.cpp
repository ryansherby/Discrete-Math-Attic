#include <vector>
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdint>
#include <ctime>

using namespace std;

class Student{

    private:
        string _fname,_lname;

    public:

        Student(string fname="", string lname=""):_fname(fname),_lname(lname){}

        string to_string(){
            ostringstream os;
            os<<_fname<<" "<<_lname;
            return os.str();
        };


        static string rotate_vowels(string s){
            char low[5]={'a','e','i','o','u'};
            char upp[5]={'A','E','I','O','U'};

            for(size_t i=0;i<s.length();i++){
                for(size_t j=0;j<5;j++){
                    if(s[i]==low[j]){
                        s[i]=low[(j+1)%5];
                        break;
                    }
                    if(s[i]==upp[j]){
                        s[i]=upp[(j+1)%5];
                        break;
                    }
                }    
            }
            return s;
        }

        static Student generate_student(){
            string v = "aeiou";
            string c = "bcdfghjklmnpqrstvwxyz";
            string name;

            int r_num =rand()%2;

            for(int i =0;i<5;i++){
                if(r_num%2==0){
                    name+=c[rand()%c.length()];
                    r_num+=1;
                }
                else{
                    name+=v[rand()%v.length()];
                    r_num+=1;
                }
            }
            return Student(name,rotate_vowels(name));
        };


};



class HashMap{
    private:

        struct Pair{
            Student _student;
            int _id;
            bool _occupied;

            Pair(const Student& student=Student(), int id=0,bool occupied=false): _student(student),_id(id),_occupied(occupied){}

            string to_string(){
                ostringstream os;

                os<<"{"<<_id<<" : "<<_student.to_string()<<"}"<<endl;

                return os.str();
            }

        };

        vector<Pair> _map;
        size_t _n;
        size_t _size;

    public:

        HashMap(size_t n=1){
            _size=0;

            _n=(2*n - (n/2));
            _map.resize(_n);
        };

    
        int hash(const int id){
            return id % _n;
        }

        void insert(const int& id, Student& student){
            int index = hash(id);
            int increment=0;

            // Linear probing to resolve collisions
            while (_map[index]._occupied){
                if (_map[index]._id==id){
                    _map[index]._student=student; // Replaces with updated value
                    return;
                }
                increment++;
                index = hash(id+increment);
            }

            // Exits where no collision
            _map[index]=Pair(student,id,true);
            _size++;

        };


        void remove(const int& id){
            int index = hash(id);
            int increment=0;

            // Linear probing to find the key
            while (_map[index]._occupied) {
                if (_map[index]._id==id) {
                    _map[index]=Pair();
                    _size--;
                    return;
                }
                increment++;
                index = hash(id+increment);
            }
        }


        Student get(const int& id) {
            int index = hash(id);
            int increment=0;

            // Linear probing to find the key
            while (_map[index]._occupied) {
                if (_map[index]._id == id) {
                    return _map[index]._student;
                }
                increment++;
                index = hash(id+increment);
            }
            return Student();
        }


        string to_string(){
            ostringstream os;
            int iter=0;
            int i=0;

            os<<"Visual Representation of Known Hashmap Values"<<endl<<endl;
            while(iter<_size && iter<25){
                if(_map[i]._occupied){
                    os<<_map[i].to_string();
                    iter++;
                }
                i++;
            }
            return os.str();
        }


        
        static int generate_6_digit_id(){
            return rand() % 90000 + 100000;
        };

};



int main(){
    srand(static_cast<unsigned>(time(nullptr)));

    HashMap hashmap(25);

    for(int i = 0; i<24;i++){
        Student student=Student::generate_student();
        int id=HashMap::generate_6_digit_id();
        hashmap.insert(id,student);
    }

    Student student("John","Doe");

    int id = 101010;

    hashmap.insert(id,student);

    cout<<hashmap.to_string()<<endl<<endl;

    cout<<hashmap.get(id).to_string();

    hashmap.remove(101010);

    cout<<hashmap.get(id).to_string();

}

