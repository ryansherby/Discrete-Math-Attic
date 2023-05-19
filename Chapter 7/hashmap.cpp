#include <vector>
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdint>

using namespace std;


class Hash{
    private:
        struct Student{
            string _fname,_lname;
            Student(string fname="", string lname=""):_fname(fname),_lname(lname){}

            string get_name(){
                ostringstream os;
                os<<_fname<<" "<<_lname;
                return os.str();
            };
        };
        vector<Student> _map;
        size_t _n;
    public:

        
        static int generate_9_digit_id(){
            return rand() % 900000000 + 100000000;
        };


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
            return Student(name,name);
        }




        Hash(size_t n=1){
            _n=(2*n - (n/2));
            _map.resize(_n);
        };


        // Note that the assigned ID is UNCHANGED, so this function is not technically well-defined
        // If the _map is cleared, a the same ID could result in a different location (Each domain not mapped to single co-domain)
        // A solution could be to return the id to caller, but we don't want to modify it without permission
        void set_object(int const id, Student student){
            int hash_value = id % _n;
            if (_map[hash_value].get_name()!=""){
                _map[hash_value]=student;
            }
            else{
                set_object(id+1,student);  // Increment ID until available spot is found
            }
        };


        Student get_object(int const id) const {
            return _map
        }

};