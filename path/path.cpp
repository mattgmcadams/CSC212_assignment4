/** @author Matt McAdams
  * @author Connor Allamby
  **/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

void filein(std::vector< std::vector< int > > &arr, std::string fname);
void findHiLoPoint(std::vector< std::vector< int > > &arr, int m, int n, int &Hr, int &Hc, int &Lr, int &Lc);
bool findPath(std::vector< std::vector< int > > &arr, int m, int n, int Lr, int Lc, int Hr, int Hc);


int main(int argc, char *argv[]) {

    if (argc != 4) {
        std::cout << "USAGE: <filename> <rows> <cols>" << std::endl;
    }

    std::string fname = argv[1];
    int m = std::stoi(argv[2]);
    int n = std::stoi(argv[3]);

    int Lr, Lc, Hr, Hc;
    std::string yesno;

    std::vector< std::vector< int > > arr;
    filein(arr, fname);

    findHiLoPoint(arr, m, n, Hr, Hc, Lr, Lc);

    if (findPath(arr, m, n, Lr, Lc, Hr, Hc)) {
        yesno = "yes";
    } else {
        yesno = "no";
    }

    std::cout << Lr+1 << " " << Lc+1 << " " << Hr+1 << " " << Hc+1 << " " << yesno << std::endl;

    return 0;

}


void filein(std::vector< std::vector< int > > &arr, std::string fname) {

  int val;
  std::string line;
	std::ifstream file(fname);

	while(std::getline(file, line)) {
		std::vector<int> row;
		std::istringstream myss(line);
		while( myss >> val ) {
			row.push_back(val);
		}
		arr.push_back(row);

	}

	file.close();

}

void findHiLoPoint(std::vector< std::vector< int > > &arr, int m, int n, int &Hr, int &Hc, int &Lr, int &Lc) {
    int lo = 100;
    int hi = 0;

    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (arr[i][j] < lo) {
                lo = arr[i][j];
                Lr = i;
                Lc = j;
            }
            if (arr[i][j] > hi) {
                hi = arr[i][j];
                Hr = i;
                Hc = j;
            }
        }
    }
}

bool findPath(std::vector< std::vector< int > > &arr, int m, int n, int x, int y, int tar, int get) {

    // TODO: find a way to optimize this algorithm

    int current = arr[x][y];
    int target = arr[tar][get];

    //recursive, start at low point and find path which keeps going up)
    arr[x][y]=-1;
    if (current == target) {
        return true;
    } else {
        //look around. if adjacent dir contains a higher number, findPath(adj).
        if (x-1 >= 0 ){
            if(arr[x-1][y] >= current && arr[x-1][y] != -1){
                if(findPath(arr, m, n, x-1, y, tar, get)){
                    return true;
                }
            }
        }
        //if not, move to next adj dir
        if (y-1 >= 0){
            if (arr[x][y-1] >= current && arr[x][y-1] != -1){
                if(findPath(arr, m, n, x, y-1, tar, get)){
                    return true;
                }
            }
        }
        if (x+1 < m){
            if (arr[x+1][y] >= current && arr[x+1][y] !=  -1){
                if(findPath(arr, m, n, x+1, y, tar, get)){
                    return true;
                }
            }
        }
        if (y+1 < n){
            if (arr[x][y+1] >= current && arr[x][y+1] != -1){
                if(findPath(arr, m, n, x, y+1, tar, get)){
                    return true;
                }
            }
        }
        arr[x][y]=current;
        return false;

    }

}
