#include <stdlib.h>
template <class T>
class vector {
   private:
      T *v;
      int s;
   public:
      vector(){
	 s=0;
	 v=NULL;
      }
        vector(vector<T> &other){
		*other = new vector<int>(v);
	}
	void operator=(vector<T> &other){
		vector<int> v;
		other = v;
	}	


	~vector(){
	 delete [] v;
      }
      int size() {
	 return s;
      }
      void push_back(T ele) {
	 T *temp;
	 temp = new T[s];
	 for(int i=0; i<s-1; i++)
	    temp[i]=v[i];

	 delete [] v;
	 s++;
	 v = new T[s];

	 for(int i=0; i<s-1; i++)
	    v[i]=temp[i];

	 v[s-1]=ele;
	 delete [] temp;
      }
	
	T at(int){
		
	}
	T operator[](int){
		//pointer to get to the int
		//return value in location
		v++;
		return v[at(s)];

	}
	



};
