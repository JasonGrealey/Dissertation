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
	// Xi, is now the number of times which any certain mutation appears, eg is mut 1 occurs 100 times then xi_100 ++ 

//################################################################################################################
//################################################################################################################
//################################################################################################################
//################################################################################################################
//################################################################################################################


#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <sstream>

using namespace std;

int Nmut=1 ;
int Nspm=0 ;

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
    
    // initalising Grid attribute
    Grid(int p);
    //operator string() const { return "Hi"; }
    
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

/*	void MutCount(int *mutbin){
	for (int i=0;i<mutations.size();i++){
	//vector <int> mutbin;
	mutbin[mutations[i]] = mutbin[mutations[i]] + 1;
		}	
	}
*/
};

//creating genotype vector
vector <Genotype*> gens ;
//doing 150000 mutations bin
vector <int> bin (12000);

	

//bin.clear();



//creating number vector
//vector <int> numb;


//grid constructor
Grid::Grid(int p){
    //initalising genotypes into the grid
	Genotype *g0=new Genotype() ;
	gens.clear() ;
	gens.push_back(g0) ;
	
    //argument of Grid becomes length and height of grid
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
   
    
    
    
    
    
    
	//want a timestep method so we can randomly choose cell that is infected and spread to /
	// neighbour
    
	//setting time parameter
	int t = 0;
	// setting number of infected parameter
	//double n = 1;vector<int>* random
	// setting matching parameter which is 1 if sampled types are the same and 0 otherwise 
	double k = 0;
	int N=1;
	double nsamp =0;
	double phi = 0;
	double dis;
	int types = 10;

	string filename;
	ofstream files;
	//defining parameter p	
	//double phi;
	//double ntimesteps = 100000;
	//double tnorm = t/ntimesteps;
	

	
	//now to remove the spatial dependence

//int bin[gens.size()];
//for int
//-1




/*

    while (t <= 100000) {
        
        int x,y,l,m ;
        do {
            x = rand()%L;
            y = rand()%L;
		l=rand()%L;
		m=rand()%L;
            //if randomly selecting a infected cell
        } while(grid[x][y].Inf == 0) ;
*/

	/*
        //constant arrays to choose spread direction
	const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1} ;
        //random integer to choose direction of spread
	int d=rand()%4 ;
            //replication and mutation
	

	*/


	/*	if (grid[(x+dx[d]+L)%L][(y+dy[d]+L)%L].Inf==0) {
		grid[(x+dx[d]+L)%L][(y+dy[d]+L)%L].Inf=1 ;
	  */         



	 //number of cells increases
	

/*
	if (grid[(l)%L][(m)%L].Inf==0) {
		grid[(l)%L][(m)%L].Inf=1 ;
            //number of cells increases
	

		N++;
		
		
		
		

            //1 in 100 chance of mutation given infected cell picked
	
		
		if (rand()%100==0) {
			Nmut++ ;

		//cout << " a " << endl;
		//new type taken on at daughter cell
	//			grid[(x+dx[d]+L)%L][(y+dy[d]+L)%L].Type=Nmut ;

		// non spatial

			grid[(l)%L][(m)%L].Type=Nmut ;

		//cout << "b" << endl;
		
		//want here to update the number             
		
		//new genotype takes parents type - 1

		Genotype *gnew=new Genotype(gens[grid[x][y].Type -1]) ;
		//cout << "c" << endl;
		//this new genotype is then pushed to the back of the daugthers genotype
		//also from argument of the constructor we add Nmut++ also
		gnew->MutCount(bin);
		//cout << "d" << endl;
 		
	
			
		gens.push_back(gnew) ;
		//cout << "e" << endl;		
	}
           
		

				 //replication only
            else {

			
                //again number of cells increases
		//	grid[(x+dx[d]+L)%L][(y+dy[d]+L)%L].Type=grid[x][y].Type ;
		//non spatial		
	
			//new random cell takes same type 
			
		//	cout << "a" << endl;	
			grid[(l)%L][(m)%L].Type = grid[x][y].Type ;
	
			//counting mutations present in the parent cell
			gens[grid[x][y].Type-1]->MutCount(bin);
	//		for(int i=1;i<gens.size();i++){cout << bin[i] << endl;};
		}
	}
	        else{

        }




	
	//here write to a new file the value of k/n for 100 timesteps        
        //if( fmod(t,100) == 0 && t >= 2500){
	//...
	//phi = k/(nsamp);
	//ofstream timefile;
	//timefile.open("phitime.txt", ios::trunc);
	
	//cout << t << " " << nsamp << " " << k << endl;
	//distfile << t << "," << phi << endl;

	//closing the phi file
	
	//}
        
        t = t + 1;
	//cout << t << endl;
    }


*/










//	spatial loop

    while (t <= 1000000000) {
       // while(N<=1000000 || Nmut == 100000){
        int x,y,l,m ;
        
	 if( Nmut == 10000 || N == 1000000){
		cout << N << endl;		
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
		if( fmod(N,10000) == 0){
		cout <<	"Ncells = " << N << " , "  << "Nmut =" << " "  << Nmut << endl;
		}
		
		
		

            //1 in 100 chance of mutation given infected cell picked
		if (rand()%100==0) {
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
	  






	//	}
	//if(grid[x][y].Type == 1 && rand()%50 == 2) {
	//	grid[x][y].Type = 2;
	//	}
	//if(grid[x][y].Type == 2 && rand()%50 == 1) {
	//	grid[x][y].Type = 1;
	//	}
		

	        
        //Creating sampling loop
	//make loop do nothing if the two random points don't contain infected cells
	
	//if both random cells are infected and of the same type increase k.
	//if(grid[x][y].Inf == 1 && grid[l][m].Inf == 1){
	//nsamp = nsamp + 1;
	//if(grid[x][y].Type == 2 && grid[l][m].Type == 2){
	//k= k+ 1;
	



	// NEED TO MOVE THIS DISTANCE SAMPLING OUTSIDE OF THE TIME LOOP
	//------------------------------------------------------------
	//we want the distance between these two sampled points
	//and to print the distance and 
	//phi = k/(nsamp);	
	//dis = Dis(x,y,l,m);
	//distfile << dis << "," << phi << endl;
	//	}
	//else if(grid[x][y].Type == 1 && grid[l][m].Type == 1){
	//k= k+ 1;
	//phi = k/(nsamp);	
	//dis = Dis(x,y,l,m);
	//distfile << phi << "," << dis << endl;
	//	}
	//else {
	//}
	//}
	
	
	//here write to a new file the value of k/n for 100 timesteps        
        //if( fmod(t,100) == 0 && t >= 2500){
	//...
	//phi = k/(nsamp);
	//ofstream timefile;
	//timefile.open("phitime.txt", ios::trunc);
	
	//cout << t << " " << nsamp << " " << k << endl;
	//distfile << t << "," << phi << endl;

	//closing the phi file
	
	//}
        
        t = t + 1;
	//cout << t << endl;
    }
	//}


	/*
	//making a file to pring phi and distance to.
	ofstream distfile;
	distfile.open("phidist.txt",  ios::trunc);

	
	int a = 1.5*L;
	int hist[a];

	for(int i=0;i<=a;i++){
	hist[i]=0;
	//distfile << i << "," << hist[i] << endl;
	}

	int x,y,l,m;
	for(int i =0; i<1000000; i++){
	x = rand()%L;
        y = rand()%L;
	l = rand()%L;
	m = rand()%L;
	
	
	//if two random points have cells present
	if(grid[x][y].Inf == grid[l][m].Inf && grid[x][y].Inf != 0){
	
	//if they're of the same type the
	if(grid[x][y].Type == grid[l][m].Type){
	int dis = int( Dis(x,y,l,m));
	
	hist[dis] = hist[dis] + 1;
	//nsamp++;
			}
	
	

	//closing double infection if loop
		}	
	//closing for loop	
	}
	

	
	//here we are outputting the graph of distance vs amount of times where types are similar
	
	int npoints = 0;	
	for(int i=0;i<=a;i++){	
//	distfile << i << "," << hist[i] << endl;
	npoints += hist[i];
	}

	
	double histd[a];
	for(int i=0;i<=a;i++){	
	histd[a] = hist[i]/(double)npoints;
	distfile << i << "," << histd[a] << endl;
	//cout << i << hist[i] << endl;	
	}
	distfile.close();

	*/
//============================ sampling large number of points =============================================

/*
	ofstream xifile;
	xifile.open("xi.txt",  ios::trunc);
	int count[types];
	int xi[types];
	//
	for(int i=0;i<=types;i++){
	count[i]=0;
	xi[i]=0;
	//distfile << i << "," << hist[i] << endl;
	}
	int b,c;
	for(int i =0; i<types; i++){
	b = rand()%L;
    c = rand()%L;
	//l = rand()%L;
	//m = rand()%L;
	
	
	//if cell picked is present, increase count hist
	if(grid[b][c].Inf == 1){
	count[grid[b][c].Type] = count[grid[b][c].Type] + 1;
			}
	
	
	//closing for loop	
	}
	
	for(int i=0;i<=types;i++){
	for(int j=0;j<=types;j++){
	
	if(count[j]==i){
	xi[i] = xi[i] +1;
	}			
			
		
		
			}
	xifile << i  << ',' << xi[i] << endl;	
		}
	xifile.close();
*/




//	while (nsamp <= 100000) {
        
//        int x,y,l,m ;
//        do {
//            x = rand()%L;
//            y = rand()%L;
           // l = rand()%L;
           // m = rand()%L;
           
//        } while(grid[x][y].Inf == 0) ;
	
//	//finding an infected point to sample around
//	if(grid[i][j].Inf==1){	
	
	//sampling this point 
//	for(int i = 0; i<1000; i++){	
//	l = rand()%L;
 //       m = rand()%L;
//	//if new random point has a cell present and 
//	if(grid[l][m].Inf==1 && Dis(x,y,l,m) ){
//	nsamp = nsamp +1;
	
//	}
//
//	}
//	
//	}
//
		
//	}


//closing the distance file	 
	
	//if(grid[x][y].Inf == 1 && grid[l][m].Inf == 1){
	//nsamp = nsamp + 1;
	//if(grid[x][y].Type == 2 && grid[l][m].Type == 2){
	//k= k+ 1;
	



	// NEED TO MOVE THIS DISTANCE SAMPLING OUTSIDE OF THE TIME LOOP
	//------------------------------------------------------------
	//we want the distance between these two sampled points
	//and to print the distance and 
	
	//phi = k/(nsamp);
	//dis = Dis(x,y,l,m);
	//distfile << dis << "," << phi << endl;
		//}
	//else if(grid[x][y].Type == 1 && grid[l][m].Type == 1){
	//k= k+ 1;
	//phi = k/(nsamp);	
	//dis = Dis(x,y,l,m);
	//distfile << dis << "," << phi << endl;
		//}
	//else { //cout << i << endl;
	//}
	//}
	//}
	


/*
for (int i = 1; i <= 20; i++) {
	stringstream a;
	a << i;
	//making many types of files
	filename = "type_" + a.str();
	filename += ".txt";
	//checking they exist
//	cout << filename << endl;
	files.open(filename.c_str(), ios::trunc);
	
	files << 0 << ',' << 0  << endl;
	
	for (int l =0; l<L; l ++) {
		for (int j = 0; j<L; j ++) {
		if(grid[l][j].Inf==1 && grid[l][j].Type == i){
		files << l << "," << j << endl;
			}
					}
		
				
				}         
	files.close();
	//files[l] << "Some rezult " << ;
    
	
	
}	
	*/
	

  



















//    string name = "type_";     //base pattern of file name
//    ofstream files[types];      //creating array of number of  int 'types' output file streams
//    for(int l = 1; l <= types; ++l) {   //open all file streams 
//        files[l].open(name + char('l') + ".txt");
 //   }
//
 //   for(int l = 1; l <= types; ++l) { // write value of i to i-th stream
//	for (int i =0; i<L; i ++) {
//		for (int j = 0; j<L; j ++) {
//		if(grid[i][j].Inf==1 && grid[i][j].Type == l){
//		files[l] << i << "," << j << endl;
//			}
//					}
//				}         
	
	
	//files[l] << "Some rezult " << ;
//    }

	
  //writing to the file infected type one cells
  //  ofstream myfile;
  //  myfile.open("new.txt", ios::trunc);
	//	for (int i =0; i<L; i ++) {
	//	for (int j = 0; j<L; j ++) {
	//	if(grid[i][j].Inf==1 && grid[i][j].Type == 1){
	//	myfile <<i << "," << j << endl;
	//		}
	//				}
	//			}
	//myfile << "wat" << endl;
//   	myfile.close();
//	//writing type two infected positions
 // ofstream file;
   // file.open("type2.txt");
	//for (int i =0; i<L; i ++) {
	//	for (int j = 0; j<L; j ++) {
	//	if(grid[i][j].Inf==1 && grid[i][j].Type == 2){
	//	file << i << "," << j << endl;
	//	}
	//					}
	//			}
	//myfile << "wat" << endl;
   	//file.close();



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


int main() {
    
    // seeding the random number
    srand(time(NULL));
    
    
    
    //testing the random number
    // cout << rand() % 100 + 1 << endl;
    
    //testing with grid of size length and height 100
    Grid G(10000);

	ofstream chifile;
    chifile.open("chi.txt");






    cout <<"Ngens="<<gens.size()<<endl ;
/*   for (int i=0;i<gens.size();i++)
        {
            gens[i]->print();
            }
  */
  //  cout << gens.size();
    int chi[gens.size()];
    for(int i =0;i<=gens.size();i++){
        chi[i]=0;
	//to compensate for the first mutation being not being counted
	// i increase the value of chi[1] to compensate for this	
	if(i==1){
		chi[i]=chi[i]+1;
		}       
       // cout << chi[i] << ' ' << i << endl;
    }


    for (int i =0; i<= (gens.size()-1); i++)
    {	//cout << gens[i]->Size() << endl; 
	for(int j=0; j<=(gens.size()-1); j++)
        {
            int a = gens[j]->Size();
             if(i==a) {
                chi[i]=chi[i]+1;
             
             }      
		else{
                 } 
	}
	
	}
	for (int i = 1; i <= (gens.size()-1); i++){
	chifile << i << ',' << chi[i] << endl;
	}
	
	
	chifile.close();
	/*for (int i =0; i<=(gens.size()-1); i++)
	{gens[i]-> print();
	}
	*/
	
        /*for(int j=0;j<=100; j++)
        {
            int a = gens[j]->Size();
             if(i==a) {
                chi[i]=chi[i]+1;
                cout<<chi[i] <<' '<< i<< endl;
             }
             else{
                 } */
            
            /*(i==gens[j]->Size()){
                chi[i]++;
               cout << chi[i] << endl;
            }*/
        //gens[i]->Size();
    
      //    cout << chi[i] << endl;
        //Genotype *a;
        //a[i] = gens[i];
       // gens[i]->print()
    //}



    //printing the grid
    //cout << G;
    
/*	for (int i =0; i<=(gens.size()-1);i++){
	cout<<bin[i]<<endl;
	}
*/    
   
    //initalising array d
    int* d ;
    
    
    
    
    
        int chinew[gens.size()];
	for(int i=0;i<=(gens.size());i++){
	//cout << bin.at(i) << endl;
        chinew[i]=0;
	}

    //now to create a hist bin
    //here we are comparing the actual value form the paper of (Xi) ling et all

    
    ofstream chinewfile;
    chinewfile.open("chinew.txt");
    for (int i =0; i<= (gens.size()-1); i++)
    {	//cout << gens[i]->Size() << endl;
        for(int j=0; j<=(gens.size()-1); j++)
        {
            if (bin.at(j)==i) {
                chinew[i]++;
            }
                
            
            else{
            }
        }
        
    }
    for (int i=0; i<=gens.size(); i++) {
        chinewfile << i << ',' << chinew[i] << endl;
        //cout << chinew[i] << endl;
    }
    
    chinewfile.close();
    







    //printing d which shows where the infected cell is
    //d = G.Iteration();
    //for(int i =0; i < 2; i++){
    // cout << d[i] << ',';
    //}
    //cout << endl;
    

    return 0;
} 
