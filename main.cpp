#include <iostream>

using namespace std;

class Multime
{
private:

  int v[100], n;
  
public:
  int *get_v (){ return v; }
  int get_n (){ return n; }
  void set_v (int x[100]){
    for (int i = 0; i < n; i++)
      v[i] = x[i];
  }
  void set_n (int m){ m = n; }
  Multime ();
  Multime (int x[], int m);	//constructori de initializare
  Multime (const Multime & m);	//constructor de copiere
  ~Multime ();
  void convert (int x[100], int m);
  friend Multime operator + (Multime m1, Multime m2);
  friend Multime operator * (Multime m1, Multime m2);
  friend Multime operator - (Multime m1, Multime m2);
  friend ostream& operator<<(ostream&, const Multime&);
  friend istream& operator>>(istream&, Multime&);
};


ostream& operator<<(ostream& out, const Multime& m){
    out << m.v[0];
    for(int i = 1; i < m.n; i++){
        out << ", " << m.v[i];
    }
    return out;
}

istream& operator>>(istream &in, Multime& m){
    int n;
    cout<<"n = ";
    in>>n;
    m.n=n;
    for (int i = 0; i < n; i++){
        in>>m.v[i];
    }
    return in;
    
}




Multime::Multime (){
  n = 0;
}

Multime::Multime(int x[], int m){
  int k = 0, ok;
  for (int i = 0; i < m; i++){
      ok = 1;
      for (int j = 0; j < k; j++)
	if (x[i] == v[j])
	  {
	    ok = 0;
	  }
      if (ok){
	  v[k++] = x[i];
	    }
    }
    n=k;
}

Multime::Multime(const Multime & m){
  n = m.n;
  for (int i = 0; i < n; i++){
      v[i] = m.v[i];
    }
}

Multime::~Multime (){
  n = 0;
}

void Multime::convert(int x[100], int m){
  int k = 0, ok;
  for (int i = 0; i < m; i++){
      ok = 1;
      for (int j = 0; j < k; j++)
	if (x[i] == v[j]){
	    ok = 0;
	  }
      if (ok){
	  v[k++] = x[i];
	    }
  }
  n=k;
}

Multime operator + (Multime m1, Multime m2){
    int n, m, v[200], *p1, *p2, k, ok, i, j;
    n = m1.get_n();
    m = m2.get_n();
    p1 = m1.get_v();
    p2 = m2.get_v();
    for (i = 0; i < n; i++){
	    v[i] = p1[i];
    }
    k=n;
    for (i = 0; i < m; i++){
        ok=1;
        for (j = 0; j < n; j++){
            if(p1[j]==p2[i]){
                ok=0;
            }
        }
        if(ok){
            v[k++]=p2[i];
        }
    }
    Multime M(v,k);
    return M;

}

Multime operator * (Multime m1, Multime m2){
    int v[200], *p1, *p2, k, ok, n, m;
    p1 = m1.get_v ();
    p2 = m2.get_v ();
    n = m1.get_n ();
    m = m2.get_n ();
    k = 0;
    for (int i = 0; i < m1.get_n(); i++){
        ok = 0;
        for (int j = 0; j < m2.get_n (); j++){
	        if (p1[i] == p2[j]){
	            ok = 1;
	        
	        }
	    }
        if (ok){
	    v[k++] = p1[i];
	    }
    }
    Multime M (v, k);
    return M;

}

Multime operator - (Multime m1, Multime m2){
  int v[200], *p1, *p2, k, ok;
  p1 = m1.get_v ();
  p2 = m2.get_v ();
  k = 0;
  for (int i = 0; i < m1.get_n (); i++){
      ok = 0;
      for (int j = 0; j < m2.get_n (); j++){
	  if (p1[i] == p2[j]){
	      ok = 1;
	    }
	}
      if (ok == 0){
	  v[k++] = p1[i];
	}
    }
  Multime M (v, k);
  return M;

}


void citire_array(Multime v[100]){
    cin>>n;
    cout<<"Elementele vectorului de obiecte\n";
    for(int i = 0; i < n; i++){
        cout<<"Elementul nr. "<<i+1<<"\n";
        cin>>v[i];
    }
    cout<<"\n";
    for(int i = 0; i < n; i++){
        cout<<v[i]<<"\n";

    }
}
    

int main (){
    int v[] = { 4, 3, 7, 5, 2, 3, 4, 5, 6, 7, 8, 11, 3, 5, 7, 1 }, n = 16,	//4,3,7,5,2,6,8   - > 4,3,7,5,2,6,11,23,1
    v2[] ={3, 11, 23, 4, 5, 7}, n2 = 6;	//3,11,23,4,5,7,1 - > 4,3,7,5,11
    Multime Set (v, n);		//                 - > 2,6,8
    Multime Set2 (v2, n2);
    cout<<Set<<"\n"<<Set2;
    Multime X;
    X=convert(v,n);
    cout<<X;
    X = Set + Set2;
    cout<<X<<"\n";
    X = Set * Set2;
    cout<<X<<"\n";
    X = Set - Set2;
    cout<<X<<"\n";
    Multime Z;
    cin>>Z;
    cout<<Z<<"\n";
    cout<<"Numarul de elemente: ";
    cin>>n;
    cout<<endl;
    Multime S[100];
    cub
    citire_array(S,n);
    
    for(int i=0;i<n;i++){
        cout<<S[0]<<"\n";
    }
    
  return 0;
}
