//
//  main.cpp
//  Simplemodel
//
//  Created by Jason Grealey on 26/09/2016.
//  Copyright � 2016 Jason Grealey. All rights reserved.
//

//################################################################################################################
//################THINGS TO DO####################################################################################
//################################################################################################################
//################################################################################################################
	//LOOK AT CHANGING RANDOM NUMBER GENERATOR 	

//################################################################################################################
//################################################################################################################
//################################################################################################################
//################################################################################################################
//################################################################################################################

#define WELL_MIXED
//#define SPATIAL



#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
//#include <sstream>
//#include <math>

using namespace std;

int Nmut=1 ;
int Nspm=0 ;
int Nmax = 100000;
int Nmutmax = 10000;
int chance = 100;
int Lmax=1000 ;

 double Dis(int a, int b, int c, int d)
	{
	int distx = (a-c)*(a-c); 
	int disty = (b-d)*(b-d);
	double v;
	v = sqrt(distx + disty);
	return v;
	}

//methods for determining whether a point is on the lattice or not
class Cell{
public:
    int Inf;
	//introducting cell type
	int Type;
    
    
    
};



//Grid class
class Grid{
    
    
    
    //attributes
public:
    int L; //length of lattice
    //intialising a grid 2-d array with Cell attibutes
    Cell ** grid;
    
    //initialising interation method array
    int *Iteration();
    
   // int IRight();
    
    // initalising Grid constructor
    Grid(int p);
    //operator string() const { return "Hi"; }

    void 	find_mut_frequency(char *name) ;
	 void 	find_chi(char *name) ;
	 void 	find_xi(char *name) ;


    
};

ostream & operator<<(ostream & Str, Grid const & v) {
    // print something from v to str, e.g: Str << v.getX();
    for (int i =0; i<v.L; i ++) {
        for (int j =0; j<v.L; j ++) {
            Str << v.grid[i][j].Inf << ' ';
            
        }
        
        Str << endl;
    }
    return Str;
}



class Genotype {
	public:
	
	//defining integer vector containing numbers of mutation
	vector <int> mutations ;
	//clearing the mutations sopy constructor
	Genotype() { mutations.clear() ; }
	
		//genotype constructor with pointer argument
	Genotype( Genotype *prev) {
	//constructor with new genotype argument copies old mutations
		mutations = prev->mutations ;
        //and now also we push back the new mutation 
		mutations.push_back(++Nspm) ;
	}
    //print function, prints the mutations contained in a genotype
  void print() {
    for (int i=0;i<mutations.size();i++) cout <<mutations[i]<<" " ; cout <<endl ;
                }
    //function to return the number of mutations present in a cell
    int Size()
    {
        int sum=0;
        for (int i=0;i<mutations.size();i++){
           if(mutations[i]!=0){ sum ++; }
        }
        return sum;
            }
  //method for increasing mutbins values s.t we can count #times each mutation is present 
	void MutCount(vector<int> &mutbin){
	for (int i=0;i<mutations.size();i++){
	//vector <int> mutbin;
		mutbin[mutations[i]] = mutbin[mutations[i]] +1;

		}	
	}


};

//creating genotype vector
vector <Genotype*> gens ;
//doing 150000 mutations bin
vector <int> bin (110000);

	




//creating number vector
//vector <int> numb;


//grid constructor
Grid::Grid(int p){
    //initalising genotypes into the grid
	Genotype *g0=new Genotype() ;
	gens.clear() ;
	gens.push_back(g0) ;
	
    //argument of Grid becomes length and height of grid
    
	//int * foo;
	//foo = new int [L];


	L = p;
    //defining a grid as a 1-d Cell array
    grid = new Cell*[L];
    for (int i =0; i<L; i ++) {
        // making every 1-d cell [i] have another dimension - of lenth L - making 2-d grid
        grid [i] = new Cell [L];
        
        
        for (int j =0; j<L; j ++) {
            
            
		//making all cells uninfected
		grid[i][j].Inf = 0;
		//making all cells type zero
		grid[i][j].Type = 0;

		//infecting middle cell
		if (i == (L/2 -1) && j ==(L/2 -1)){
		grid[i][j].Inf = 1;
		grid[i][j].Type = 1;
						}
            
				}
        
        
		}
   

	//setting time parameter
	int t = 0;
	// setting number of infected parameter
	
	// setting matching parameter which is 1 if sampled types are the same and 0 otherwise 
	double k = 0;
	int N=1;
	double nsamp =0;
	double phi = 0;
	double dis;


#ifdef WELL_MIXED
  //this will be now compiled 

cout << "This is the Well-Mixed Model" << endl;


    while (t <= 100000000) {
        
        int x,y,l,m ;
        
		 if( Nmut == Nmutmax || N == Nmax){
		cout << "loop finished" << endl;		
		cout <<	"Ncells = " << N <<" , "<<"Nmut ="<<" "<< Nmut << endl;		
		break;	
			}



	do {
            x = rand()%L;
            y = rand()%L;
		l=rand()%L;
		m=rand()%L;
            //if randomly selecting a infected cell
        } while(grid[x][y].Inf == 0) ;



	 //number of cells increases
	


	if (grid[(l)%L][(m)%L].Inf==0) {
		grid[(l)%L][(m)%L].Inf=1 ;
            //number of cells increases
	

		N++;
	
		if( (N%(Nmax/10)) == 0){
		cout <<	"Ncells = " << N << " , "  << "Nmut =" << " "  << Nmut << endl;
		}
            //1 in 100 chance of mutation given infected cell picked
	
		
		if (rand()%100==0) {
			Nmut++ ;


		//new type taken on at daughter cell




			grid[(l)%L][(m)%L].Type=Nmut ;


		
		//want here to update the number             
		
		//new genotype takes parents type - 1

		Genotype *gnew=new Genotype(gens[grid[x][y].Type -1]) ;

		//this new genotype is then pushed to the back of the daugthers genotype
		//also from argument of the constructor we add Nmut++ also
		gnew->MutCount(bin);

		gens.push_back(gnew) ;
	
	}

				 //replication only
            else {

			//new random cell takes same type 

			grid[(l)%L][(m)%L].Type = grid[x][y].Type ;
	
			//counting mutations present in the parent cell
			gens[grid[x][y].Type-1]->MutCount(bin);

		}
	}


        
        t = t + 1;
    }

#endif










#ifdef SPATIAL
//	spatial loop

cout << "This is the Spatial Model" << endl;


    while (t <= 1000000000) {
       // while(N<=1000000 || Nmut == 100000){
        int x,y,l,m ;
        
	 if( Nmut == Nmutmax || N == Nmax){
		cout << "loop finished" << endl;		
		cout <<	"Ncells = " << N <<" , "<<"Nmut ="<<" "<< Nmut << endl;		
		break;	
		}



	do {
		
            x = rand()%L;
            y = rand()%L;
            //if randomly selecting a infected cell
        } while(grid[x][y].Inf == 0) ;
        //constant arrays to choose spread direction
	const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1} ;
        //random integer to choose direction of spread
	int d=rand()%4 ;
            //replication and mutation
		  
	if (grid[(x+dx[d]+L)%L][(y+dy[d]+L)%L].Inf==0) {
		grid[(x+dx[d]+L)%L][(y+dy[d]+L)%L].Inf=1 ;
            //number of cells increases
	

		N++;
		if( (N%(Nmax/10)) == 0){
		cout <<	"Ncells = " << N << " , "  << "Nmut =" << " "  << Nmut << endl;
		}
		
		
		

            //1 in 100 chance of mutation given infected cell picked
		if (rand()%chance==0) {
			Nmut++ ;
		//new type taken on at daughter cell
			grid[(x+dx[d]+L)%L][(y+dy[d]+L)%L].Type=Nmut ;
		//want here to update the number             
		
		//new genotype takes parents type - 1

		Genotype *gnew=new Genotype(gens[grid[x][y].Type -1]) ;

		//this new genotype is then pushed to the back of the daugthers genotype
		//also from argument of the constructor we add Nmut++ also
		gnew->MutCount(bin);
            gens.push_back(gnew) ;
		
		}
            //replication only
            else {
                //again number of cells increases
			grid[(x+dx[d]+L)%L][(y+dy[d]+L)%L].Type=grid[x][y].Type ;
			gens[grid[x][y].Type-1]->MutCount(bin);
	//		for(int i=1;i<gens.size();i++){cout << bin[i] << endl;};
		}
	}
	  







        t = t + 1;
	//cout << t << endl;
    }
	//}

#endif
	




	//creating an array the size of the lattice for printing 
	int array [L][L];
	for (int i =0;i<L;i++){
	for (int j=0;j<L;j++){
//	array [i][j]=0;
	//cout << array[i][j] << endl;
	}
	}
		
	//now we need to format the printing into an array
	
	ofstream arrayfile;
	arrayfile.open("array.txt",  ios::trunc);
	for (int i =0;i<L;i++){
	for (int j=0;j<L;j++){
	array[i][j]=grid[i][j].Type;
	arrayfile << array[i][j] << ',';
	}
	arrayfile << endl;
	}	
		
	
	
	arrayfile.close();
	


}

//Grid g


	







//method for checking where infected cell is
// pulling array with Grid attributes and initialising the function Iteration
int *Grid::Iteration(){
    
    //initialising array
    
    int *index;
    // {0 = i pos, 1= j pos, 2 = inf (1 or 0)}
    index = new int[3];
    
    //intialising an infected cell at {0,0}
    index [2] = 0;
    index[0] = 0;
    //already intialised above
    //index[1] = 1;
    
    
    //printing here to stop loop printing once cancer has spread
    
    cout << "Infected cells are present here" << endl;
    
    for (int i=0; i<L; i++){
        for (int j=0; j<L; j++){
            
            // printing position of infected cell
            if (grid[i][j].Inf == 1) {
                
                index [2] = 1;
                index [0] = i;
                index [1] = j;
                // cout << index[0] << ',' << index[1] << endl;
            }
        }
        
    }
    
    return index;
}

//method for 1/f distribution
void 	Grid::find_mut_frequency(char *name)
{
  float mutfreq[Nmut] ;
  int Ntot=0 ;
  for (int i=0;i<Nmut;i++) mutfreq[i]=0 ;
  ofstream file(name) ;
  for (int i=0; i<L; i++){
    for (int j=0; j<L; j++){
      if (grid[i][j].Inf == 1) {
        Ntot++ ;
        Genotype *g=gens[grid[i][j].Type-1] ;
        for (int k=0;k<g->mutations.size();k++) mutfreq[g->mutations[k]]++ ;     
      }
    }
  }
  
  for (int i=0;i<Nmut;i++) file <<1.*mutfreq[i]/Ntot<<endl ;
  file.close() ; 
}


//method for 1/f distribution
void 	Grid::find_chi(char *name)
{
  int chi[Nmut];
  int Ntot=0 ;
  ofstream file(name) ;
	//initalising
    for(int i =0;i<=Nmut;i++){
        chi[i]=0;
	//to compensate for the first mutation being not being counted
	// i increase the value of chi[1] to compensate for this	
	if(i==1){
		chi[i]=chi[i]+1;
		}       
    }


    for (int i =0; i< (Nmut); i++)
    {
	for(int j=0; j<(Nmut); j++)
        {
	//a is #mutations in a genotype
            int a = gens[j]->Size();
             if(i==a) {
                chi[i]=chi[i]+1;
             
             }      
		 
	}

	
	}
	for (int i = 1; i <= (Nmut); i++){
	file << i << ',' << chi[i] << endl;
	}
	  file.close() ; 
}


void Grid::find_xi(char *name) 
{

  ofstream file(name) ;
    
    
    	
        int chinew[Nmut];
	//initialising
	for(int i=0;i<=(Nmut);i++){
        chinew[i]=0;
	}
    //here we are comparing the actual value form the paper of (Xi) ling et all

    for (int i =0; i<= (Nmut); i++)
    {	
        for(int j=0; j<=(Nmut); j++)
        {
            if (bin.at(j)==i) {
                chinew[i]++;
            }
 
        }
        
    }

    for (int i=0; i<=Nmut; i++) {
 	file << i << ',' << chinew[i] << endl;

    }

	  file.close() ; 
}





int main() {
    
    // seeding the random number
    srand(time(NULL));
    
    //testing the random number
    // cout << rand() % 100 + 1 << endl;
    
    //testing with grid of size length and height 100
   // Grid G(2250);
	Grid *G;
	G = new Grid(Lmax);
	// Grid G(1450);



	G->find_mut_frequency("mutfreq.txt") ;
	G->find_chi("chi.txt") ;
	G->find_xi("xi.txt") ;

    //printing the grid
    //cout << G;
    

   
    //initalising array d
    int* d ;
    

	




    //printing d which shows where the infected cell is
    //d = G.Iteration();
    //for(int i =0; i < 2; i++){
    // cout << d[i] << ',';
    //}
    //cout << endl;
    

    return 0;
} 
