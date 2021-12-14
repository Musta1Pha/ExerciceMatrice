#include <iostream>

using namespace std;

 class Matrice{
   private:
    float** tab;
    int i;
    int j;
   public:
    Matrice(int i=0,int j=0);
    Matrice operator+(const Matrice& m) const;
    Matrice operator-(const Matrice& m) const;
    Matrice operator*(const Matrice& m) const;
    Matrice& operator=(const Matrice& m);
    void Afficher() const;

 };

   Matrice::Matrice(int i,int j){
     this->i = i;
     this->j = j;
       this->tab = new float*[i];
     for(int i=0;i<this->i;i++){
       this->tab[i] = new float[j];
     for(int j=0;j<this->j;j++){
       cout<<"Donnez La Valeur : ";
       cin>>this->tab[i][j];
  }
  }
  }

  Matrice Matrice::operator+(const Matrice& m) const{
     Matrice M2(i,j);
     if(this->i == m.i && this->j == m.j){
        for(int i=0;i<this->i;i++){
         for(int j=0;j<this->j;j++){
            M2.tab[i][j] = this->tab[i][j] + m.tab[i][j];
  }
  }
  }
         return M2;
  }

  Matrice Matrice::operator-(const Matrice& m) const{
     Matrice M2(i,j);
     if(this->i == m.i && this->j == m.j){
        for(int i=0;i<this->i;i++){
         for(int j=0;j<this->j;j++){
            M2.tab[i][j] = this->tab[i][j] - m.tab[i][j];
  }
  }
  }
         return M2;
  }

  Matrice Matrice::operator*(const Matrice& m)const{
      Matrice M2(this->i,m.j);
      for(int i=0;i<this->i;i++){
        for(int j=0;j<m.j;j++){
           M2.tab[i][j] = 0;
  }
  }
      if(this->j == m.i){
        for(int i=0;i<this->i;i++){
          for(int j=0;j<m.j;j++){
           for(int k=0;k<this->j;k++){
         M2.tab[i][j] += (this->tab[i][k] * m.tab[k][j]);
  }
  }
  }
  }
         return M2;
  }




  void Matrice::Afficher()const{
    for(int i=0;i<this->i;i++){
     for(int j=0;j<this->j;j++){
        cout<<this->tab[i][j]<<" ";
  }
        cout<<endl;
  }
        cout<<endl;
  }

  Matrice& Matrice::operator=(const Matrice& m){
    if(this != &m){
      if(this->i !=  m.i || this->j != m.j){
         for(int i=0;i<this->i;i++){
            delete[] this->tab[i];
  }
            delete[] this->tab;
            this->i = m.i;
            this->j = m.j;
  }
          this->tab = new float*[i];
        for(int i=0;i<this->i;i++){
           this->tab[i] = new float[j];
          for(int j=0;j<this->j;j++){
             this->tab[i][j] = m.tab[i][j];
  }
  }
  }

          for(int i=0;i<this->i;i++){
            for(int j=0;j<this->j;j++){
             this->tab[i][j] = m.tab[i][j];

  }
  }
       return *this;
  }


int main()
{
    Matrice M1(2,2);
    M1.Afficher();

    Matrice M(2,2);
    M.Afficher();

    Matrice m2;
    m2 = M1 + M;

    cout<<endl;
    cout<<"Affichage de la matrice Somme : "<<endl;
    m2.Afficher();
    cout<<endl;


    Matrice m3;
    m3 = M1 - M;
    cout<<endl;
    cout<<"Affichage de la matrice Soustraction : "<<endl;
    m3.Afficher();
    cout<<endl;

    Matrice m4;
    m4 = M1 * M;
    cout<<endl;
    cout<<"Affichage de la matrice Multiplication : "<<endl;
    m4.Afficher();
    cout<<endl;



    return 0;
}
