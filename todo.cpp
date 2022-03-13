#include<bits/stdc++.h>
#define vector vector<string>
using namespace std;
// 3 line
int main(int arg ,char ** arv) {
if(arg == 1) {					//basic guide for using todo list


  cout << "Usage :-" << "\n" << "$todo add " << "\"todo item\"" 
  << "  # Add a new todo"<<"\n"
  << "$todo ls # Show a list of todos"
  << "\n" << "$todo del NUMBER       # Delete a todo"<<"\n" 
  << "$todo done NUMBER      # Complete a todo"<<"\n" 	
  << "$todo help              # Show usage" << "\n";

  return 0;
}
else if(*arv[1] == 'h') {				//help
  cout << "Usage :-" << "\n" << "$todo add "
  << "\"todo item\"" << "  # Add a new todo" << "\n" 
  << "$todo ls                # Show a list of todos"<< "\n" 
  << "$todo rm NUMBER       # Delete a todo" << "\n"
  << "$todo done NUMBER      # Complete a todo" << "\n"
  << "$todo help              # Show usage"<< "\n";
  return 0;
}
string rr=arv[1];
time_t ttime = time(0);
tm *local_time = localtime(&ttime);
fstream fio;
string line; 
fio.open(".todo.txt", ios::out | ios::in |ios::app) ; 

if(rr=="add") {					//add 
  vector v;
  line=arv[2];
  cout<<"Added todo:"<<" "<<line<<endl;
  fio <<line<<endl;
  fio.seekg(0, ios::beg); 
  while(fio) {
 
    string str;
    getline(fio,str);
    v.push_back(str);

    }
  if(v.size()>1) {
    reverse(v.begin(),v.end());
    fio.close();
    fio.open(".todo.txt", ios::out | ios::in | ios::trunc) ;

    for(int i=1;i<v.size();i++) {

      fio<<v[i]<<endl;
    } 

    }

} //if ended

else if(rr=="rm") {				//delete

  string x=arv[2];
  int z;
  string t;
  vector p;
  while(fio) {

    getline(fio,t);
    p.push_back(t);
    }	
  fio.close();
  z=stoi(x);
  if(z==0 || z>(p.size()-1) || z<0) {

    cout<<"todo #"<<z<<"does not exist"<<endl;
    return 0;
    }

  cout<<"Deleted todo #"<<z<<endl;
  fio.open(".todo.txt", ios::out | ios::in | ios::trunc) ;
  for(int i=0;i<p.size()-1;i++) {	
    if(i==(p.size()-1)-z)
    continue;

    else
    fio<<p[i]<<endl;
    }	
}

else if(rr=="ls") {					//list
  fio.seekg(0, ios::beg); 
  vector l;
  while(fio) {    	
    getline(fio, line); 
    
 		l.push_back(line);
    		}
  int a=l.size()-1;
  for(int i=0;i<l.size()-1;i++) {
    if(i==(l.size()-1))
    cout<<"["<<a<<"]"<<l[i];
    else
    cout<<"["<<a<<"]"<<l[i]<<endl;
    a--;
    }

}


else if(rr=="done") {			//done
  int u=local_time->tm_mday;
  int q=local_time->tm_mon;
  int f=local_time->tm_year;
  string str ="x ";
  str=str+to_string(u)+"-"+to_string(q)+"-"+to_string(f)+" ";
  string a=arv[2];
  int n;
  vector g;
  fstream ff;
  ff.open("done.txt",  ios::in | ios::out | ios::app) ; 
  fio.seekg(0, ios::beg); 
  while(fio) {
    string rr;
    getline(fio,rr);
    g.push_back(rr);

    }
  fio.close();
  n=stoi(a);
  if(n==0 || n>(g.size()-1) || n<0) {

    cout<<"todo #"<<n<<"does not exist"<<endl;
    return 0;
    }
  cout<<"Marked todo #"<<n<<" as done ."<<endl;
  fio.open(".todo.txt", ios::out | ios::in | ios::trunc) ;

  for(int i=0;i<g.size()-1;i++) {
    
    if(i==(g.size()-1)-n){
      str=str+g[i];
      ff<<str<<endl;
    }

    else
      fio<<g[i]<<endl;
    }
  ff.close();
}
else
  cout << "invalid command" << "\n";

fio.close(); 
return 0;
}