/*
 * Calcolo Determinante Matrice con metodo Laplace, utilizzando una funzione Ricorsiva
 * Created on February 12, 2018, 3:20 PM - Marco Romagnoli
 */

#include <fstream>
#include <math.h>
#include <vector>

using namespace std;

int determ(const vector<vector<int>>& a, int n) 
{
  long long int det=0;
  int p, h, k, i, j;
  vector<vector<int>> temp(n-1, std::vector<int>(n-1));
  if(n==1) 
     {
       return a[0][0];  // banale: matrice 1x1...
     } 
  else if(n==2) 
  {
        det=(a[0][0]*a[1][1]-a[0][1]*a[1][0]);  // banale matrice 2x2....
        return det;
  } else 
    {
/*caso in cui n>=3  : TRE cicli For innestati: uno per ciclare su tutte le sottomatrici, gli altri due
 per ciclare su una singola matrice n-1xn-1 */
       for(p=0;p<n;p++)  
       {
           h = 0;
           k = 0;
           for(i=1;i<n;i++) 
           {
                for( j=0;j<n;j++) 
                {
                    if(j==p)  { continue;}
                    temp[h][k] = a[i][j];
                    k++;
                    if(k==n-1) 
                    {
                      h++;
                      k = 0;
                    }
                }
            }
            det=det+a[0][p]*pow(-1,p)*determ(temp,n-1);
        }
        return det;
    }
}

int main() 
{
    ifstream read("input.txt");
    ofstream write("output.txt");
    int DIM;
    read >> DIM;
    long long int determinante; 
    vector<vector<int>> a(DIM, std::vector<int>(DIM));
    for(int i=0;i<DIM;++i)
        for(int j=0;j<DIM;++j)
            read >> a[i][j];
    determinante = determ(a,DIM);
	write << DIM << endl;
    write << determinante << endl;
    return 0;
}


