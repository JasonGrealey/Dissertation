//
//  main.cpp
//  Simplemodel
//
//  Created by Jason Grealey on 26/09/2016.
//  Copyright © 2016 Jason Grealey. All rights reserved.
//

//################################################################################################################
//################THINGS TO DO####################################################################################
//################################################################################################################
//################################################################################################################
	//LOOK AT CHANGING RANDOM NUMBER GENERATOR 	
	//being to sample Xi, by bining types, then counting # of times a mut type appeared and bin it into Xi
	//plot Xi against it's bins

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
    

    // don't need this attribute because it can make it too complicated for updating after infections
    //int IsAble;
    
    
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
	
	//defining integer vector containing mutation	
	vector <int> mutations ;
	//clearing the mutations
	Genotype() { mutations.clear() ; }
	
		
	Genotype( Genotype &prev) {
		mutations = prev.mutations ;
		prev.push_back(++Nspm) ;
	}
};

vector <Genotype*> gens ;


//grid constructor
Grid::Grid(int p){
	Genotype g0 ;
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
		//making all cells white type
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
	//double n = 1;
	// setting matching parameter which is 1 if sampled types are the same and 0 otherwise 
	double k = 0;
	
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
	
	
	
	
	//divide k/n when t is of certain values
	// let n and k build per infections and then also
	//if loop for k if sampled infected points are of the same type 



    //100000
    while (t <= 10000000) {
        
        int x,y,l,m ;
        do {
            x = rand()%L;
            y = rand()%L;
            //if randomly selecting a infected cell
        } while(grid[x][y].Inf == 0) ;
        //constant arrays to choose spread direction
	const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1} ;
	int d=rand()%4 ;
	if (grid[(x+dx[d]+L)%L][(y+dy[d]+L)%L].Inf==0) {
		grid[(x+dx[d]+L)%L][(y+dy[d]+L)%L].Inf=1 ;
		if (rand()%100==0) {
			Nmut++ ;
			cout << Nmut;
			grid[(x+dx[d]+L)%L][(y+dy[d]+L)%L].Type=Nmut ;
			Genotype gnew(gens[grid[(x+dx[d]+L)%L][(y+dy[d]+L)%L].Type-1]) ;
			gens.push_back(gnew) ;
		} else {
			grid[(x+dx[d]+L)%L][(y+dy[d]+L)%L].Type=grid[x][y].Type ;
		}
	}
	        else{

        }
//===================================rightwards===================================
        
        //if(grid[x][(y+1)%L].Inf == 0 && grid[x][y].Type == 1 && rand()%5 !=0) {
	
//	if(grid[x][(y+1)%L].Inf == 0 && grid[x][y].Type != 0 && grid[x][y].Type !=1) {          
//  	grid[x][(y+1)%L].Inf = 1;
//        grid[x][(y+1)%L].Type = grid[x][y].Type;
		//n = n +1;
//        }
	
//	else if(grid[x][(y+1)%L].Inf == 0 && grid[x][y].Type == 1 && rand()%5 !=0 ) {          
//  	grid[x][(y+1)%L].Inf = 1;
//        grid[x][(y+1)%L].Type = grid[x][y].Type;
		//n = n +1;
//        }
	//else if(grid[x][(y+1)%L].Inf == 0 && grid[x][y].Type == 2 ) {
        //    grid[x][(y+1)%L].Inf = 1;
        //    grid[x][(y+1)%L].Type = 2;
		//n = n +1;
        //}
        
//==================================leftwards=============================================
      
	
	  //else if(grid[x][(y-1+L)%L].Inf == 0 && grid[x][y].Type == 1 && rand()%5 !=0 ){
//	else if(grid[x][(y-1+L)%L].Inf == 0 && grid[x][y].Type != 0 && grid[x][y].Type !=1){          
//	  	grid[x][(y-1+L)%L].Inf=1;
//		grid[x][(y-1+L)%L].Type = grid[x][y].Type;
		//n = n +1;
            
//        }

	
//	else if(grid[x][(y-1+L)%L].Inf == 0 && grid[x][y].Type ==1 && rand()%5 !=0 ){          
//	  	grid[x][(y-1+L)%L].Inf=1;
//		grid[x][(y-1+L)%L].Type = grid[x][y].Type;
		//n = n +1;
            
//        }
  	//else if(grid[x][(y-1+L)%L].Inf == 0 && grid[x][y].Type == 2 ){
        //    grid[x][(y-1+L)%L].Inf=1;
	//	grid[x][(y-1+L)%L].Type = 2;
		//n = n +1;
            
       // }
        

//=========================downwards====================================================
       
	
	 //else if(grid[(x+1)%L][y].Inf == 0  && grid[x][y].Type == 1 && rand()%5 !=0){
//	else if(grid[(x+1)%L][y].Inf == 0  && grid[x][y].Type != 0 && grid[x][y].Type !=1){          
//	  	grid[(x+1)%L][y].Inf=1;
//		grid[(x+1)%L][y].Type = grid[x][y].Type;
		//n = n +1;
            
//        }
	
//	else if(grid[(x+1)%L][y].Inf == 0  && grid[x][y].Type == 1 && rand()%5 !=0 ){          
//	  	grid[(x+1)%L][y].Inf=1;
//		grid[(x+1)%L][y].Type = grid[x][y].Type;
		//n = n +1;
            
//        }	
	
	

	//  else if(grid[(x+1)%L][y].Inf == 0  && grid[x][y].Type == 2 ){
        //    grid[(x+1)%L][y].Inf=1;
	//	grid[(x+1)%L][y].Type = 2;
	//	//n = n +1;
	//   
	// }

//===============================upwards================================================
        
	
	//else if(grid[(x-1+L)%L][y].Inf==0 && grid[x][y].Type == 1 && rand()%5 !=0){
//	else if(grid[(x-1+L)%L][y].Inf==0 && grid[x][y].Type != 0 && grid[x][y].Type !=1){            	
//		grid[(x-1+L)%L][y].Inf=1;
//		grid[(x-1+L)%L][y].Type = grid[x][y].Type;
		//n = n +1;
            
//        }
	
	
//	else if(grid[(x-1+L)%L][y].Inf==0 && grid[x][y].Type == 1 && rand()%5 !=0 ){            	
//		grid[(x-1+L)%L][y].Inf=1;
//		grid[(x-1+L)%L][y].Type = grid[x][y].Type;
//		//n = n +1;
            
//        }	
	
	
	
	
       // else if(grid[(x-1+L)%L][y].Inf==0 && grid[x][y].Type == 2){
       //     grid[(x-1+L)%L][y].Inf=1;
	//		grid[(x-1+L)%L][y].Type = 2;
	//	//n = n +1;
        //    
        //}

        //cout << x+1 << ' ' << x-1 << ' '<< y+1 << ' ' << y-1 << endl;
        
	//Changing Cell types with some probability
	//having loop of different mutation types
	//the mutations can only go backwards or forwards by one here
	
	
//	for(int i=1;i<=types;i++){
//	if(grid[x][y].Type == i && rand()%50 == 2) {
//		grid[x][y].Type = i+1;
//		}
//	}
	
//	for(int i=1;i<=types;i++){
//	if(grid[x][y].Type == i && rand()%50 == 2) {
//		grid[x][y].Type = i-1;
//		}
//	}	







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


//============================ sampling large number of points =============================================


	ofstream xifile;
	xifile.open("xi.txt",  ios::trunc);

	int count[types];
	int xi[types];
	
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



//===================================================================================
//===================================================================================
    //creating distance sampling loop after the tumour has been created
	//    int x,y,l,m ;
	//for(int i = 0; i< 10000; i++){
        //x = rand()%L;
        //y = rand()%L;
        //l = rand()%L;
        //m = rand()%L;

 	//Creating sampling loop
	//make loop do nothing if the two random points don't contain infected cells

	//want to select a ramdon cell and sample a number of random points around it
	
	
	//if(grid[x][y].Inf == 1){
	//inside this loop we will pick a number of other points and sample them
	
	//for(int i = 0; i<10000; i++){	
	//l = rand()%L;
        //m = rand()%L;
	
	//if(grid[l][m].Inf==1){
	
	//nsamp = nsamp + 1;
	
	//if(grid[x][y].Type == 1 && grid[l][m].Type == 1){

	//k=k+1;

	//phi = k/(nsamp);
	//dis = Dis(x,y,l,m);
	//distfile << dis << "," << phi << endl;
	//}
	
	//else if(grid[x][y].Type == 2 && grid[l][m].Type == 2){
	//k=k+1;

	//phi = k/(nsamp);
	//dis = Dis(x,y,l,m);
	//distfile << dis << "," << phi << endl;
	//}
	//else { //cout << i << endl;
	//}
	
	//}
	//}
	//}
	//}

//==========================================================================
//==========================================================================



	
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
    Grid G(700);
    
    // G = new Grid (10);
    
    
    //printing the grid
    //cout << G;
    
    //writing to a file
    
    //opening a file and writing positions of the cells to it
    
    
    //agadshgdahah
    //initalising array d
    int* d ;
    





	//testing the distance method
	//double alpha;
	//alpha = Dis(320,167,102,120);


	//cout << alpha << endl; 






    //printing d which shows where the infected cell is
    //d = G.Iteration();
    //for(int i =0; i < 2; i++){
    // cout << d[i] << ',';
    //}
    //cout << endl;
    
    //system("pause") ;
    return 0;
} 

