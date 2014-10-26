/**
 * @file tri_inconnu.cpp
 * @brief Programme implémentant un mystérieux algorithme de tri ...
**/


//--------------------------------------------------------------------
// Définition du type tableau
const unsigned int N = 10;
typedef int TabEntier[N];


//--------------------------------------------------------------------
// Tri inconnu : routine essentielle
void Machin(TabEntier t, unsigned int deb, unsigned int mid, unsigned int fin, int *aux)
{
   unsigned int nAux, i, j, k, l;
  
   nAux = mid - deb + 1;
   for (i=deb; i<=mid; ++i) {
    aux[i-deb] = t[i];
   }

   i = 0;
   j = mid+1,
   k = deb;
   while ((i<nAux) && (j<=fin)) 
   {
      if (aux[i]<t[j]) 
      {
         t[k] = aux[i];
         ++i;
      }
      else 
      {
         t[k] = t[j];
         ++j;
      }
      ++k;
   }

   if (i<nAux) 
   {
      for (l=i; l<nAux; ++l, ++k) 
      {
         t[k] = aux[l];
      }
   }
   else
   {
      for (l=j; l<=fin; ++l, ++k) 
      {
         t[k] = t[l];
      }
   }
} // Machin


//--------------------------------------------------------------------
// Tri inconnu : routine récursive
void Truc(TabEntier t, unsigned int deb, unsigned int fin, int *aux)
{
   unsigned int mid;

   if (deb<fin) {
      mid = (deb + fin) / 2;
      Truc(t,deb,mid,aux);
      Truc(t,mid+1,fin,aux);
      Machin(t,deb,mid,fin,aux);
   }
} // Truc


//--------------------------------------------------------------------
// Tri inconnu : point d'entrée
void TriInconnu(TabEntier t)
{
   int *aux;

   aux = new int[1 + N/2];
   Truc(t,0,N-1,aux);
   delete[] aux;
} // TriInconnu


//--------------------------------------------------------------------
// programme principal
int main(void)
{
   TabEntier t;
   
   // TODO : remplir le tableau

   TriInconnu(t);

  return 0;
}
