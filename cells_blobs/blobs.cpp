/** @author Matt McAdams
  * @author Connor Allamby
  **/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

void filein(std::vector< std::vector< int > > &arr, std::string fname);
int blobTotal(std::vector< std::vector< int > > &arr, int m, int n, int conn);
void blob4(std::vector< std::vector< int > > &arr, int x, int y, int m, int n);
void blob8(std::vector< std::vector< int > > &arr, int x, int y, int m, int n);


int main(int argc, char *argv[]) {

  if (argc != 5) {
    std::cout << "USAGE: <filename> <rows> <cols> <connections>" << std::endl;
  }

  std::string fname = argv[1];
  int m = std::stoi(argv[2]);
  int n = std::stoi(argv[3]);
  int conn = std::stoi(argv[4]);

  std::vector< std::vector< int > > arr;
  filein(arr, fname);

  int blobCount = blobTotal(arr, m, n, conn);

  std::cout << blobCount << std::endl;

  return 0;
}

int blobTotal(std::vector< std::vector< int > > &arr, int m, int n, int conn) {
  int blobCount=0;
  
  if(conn == 4){
    for (int i=0; i<m; i++){
      for (int j=0; j<n; j++){
        if (arr[i][j] == 1){
          blob4(arr, i, j, m, n);
          blobCount++;
        }
      }
    }
  }
  else{
    for (int i=0; i<m; i++){
      for (int j=0; j<n; j++){
        if(arr[i][j] == 1){
          blob8(arr, i, j, m, n);
          blobCount++;
        }
      }
    }
  }
  

  return blobCount;
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


void blob4(std::vector< std::vector< int > > &arr, int x, int y, int m, int n) {
  
  if (arr[x][y] == 0) {
    return;       // base case
  } else {
    //add 1 to blob for every connected block that doesn't return 0
    arr[x][y] = -1;
    if (x-1 >= 0 && arr[x-1][y] == 1) {
      blob4(arr, x-1, y, m, n);
    }
    if (x+1 < m && arr[x+1][y] == 1) {
      blob4(arr, x+1, y, m, n);
    }
    if (y-1 >= 0 && arr[x][y-1] == 1) {
      blob4(arr, x, y-1, m, n);
    }
    if (y+1 < n && arr[x][y+1] == 1){
      blob4(arr, x, y+1, m, n);
    }

  }
}


void blob8(std::vector< std::vector< int > > &arr, int x, int y, int m, int n){

  if (arr[x][y] == 0) {
    return;
  } else {
    arr[x][y] = -1;
    //[x-1][y-1]
    if(x-1 >= 0 && y-1 >= 0 && arr[x-1][y-1]==1){
      blob8(arr, x-1, y-1, m, n);
    }
    //[x-1][y]
    if(x-1 >= 0 && arr[x-1][y]==1){
      blob8(arr, x-1, y, m, n);
    }
    //[x-1][y+1]
    if(x-1 >= 0 && y+1 < n && arr[x-1][y+1]==1){
      blob8(arr, x-1, y+1, m, n);
    }
    //[x][y-1]
    if(y-1 >= 0 && arr[x][y-1]==1){
      blob8(arr, x, y-1, m, n);
    }
    //[x][y+1]
    if(y+1 < n && arr[x][y+1]==1){
      blob8(arr, x, y+1, m, n);
    }
    //[x+1][y-1]
    if(x+1 < m && y-1 >= 0 && arr[x+1][y-1]==1){
      blob8(arr, x+1, y-1, m, n);
    }
    //[x+1][y]
    if(x+1 < m && arr[x+1][y]==1){
      blob8(arr, x+1, y, m, n);
    }
    //[x+1][y+1]
    if(x+1 < m && y+1 <n && arr[x+1][y+1]==1){
      blob8(arr, x+1, y+1, m, n);
    }
  }

}