#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

// Just a function to read the file to the array
void filein(std::vector< std::vector< int > > &arr, std::string fname);
// The recursive function to find the blob size
int blob4(std::vector< std::vector< int > > &arr, std::vector< std::vector< bool > > &visited, int x, int y, int m, int n);
int blob8(std::vector< std::vector< int > > &arr, std::vector< std::vector< bool > > &visited, int x, int y, int m, int n);

int main(int argc, char *argv[]) {

 if (argc != 7) {
    std::cout << "Usage: <filename> <rows> <columns> <starting row> <starting col> <connection type>" << std::endl;
    exit(1);
  }
  std::string fname = argv[1];
  int m = std::stoi( argv[2] );
  int n = std::stoi( argv[3] );
  int x = std::stoi( argv[4] ) - 1; // the assignment states the rows and cols
  int y = std::stoi( argv[5] ) - 1; // start at 1, so let's try compensating
  int conn = std::stoi( argv[6] );

  if (conn != 4 && conn != 8) {
    std::cout << "<connection type> must be 4 or 8" << std::endl;
    exit(1);
  }

  std::vector< std::vector< int > > arr;
  filein(arr, fname);
  std::vector< std::vector< bool > > visited;
  std::vector<bool> row;

  for (int i=0; i<m; i++){
    for (int j=0; j<n; j++){
      row.push_back(false);
    }
    visited.push_back(row);
  }


  int blobSize;
  if (conn == 4){
    blobSize = blob4(arr, visited, x, y, m, n);
  } else if (conn == 8){
    blobSize = blob8(arr, visited, x, y, m, n);
  }



  std::cout << blobSize << std::endl;

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

// I think I wanna do a separate function for if conn = 8 ?
int blob4(std::vector< std::vector< int > > &arr, std::vector< std::vector< bool > > &visited, int x, int y, int m, int n) {

  int blobSize = 1;
  // so,
  visited[x][y] = true;
  if (arr[x][y] == 0) {
    return 0;       // base case
  } else {
    //add 1 to blob for every connected block that doesn't return 0

    if (x-1 >= 0 && !visited[x-1][y]) {
      blobSize += blob4(arr, visited, x-1, y, m, n);
    }
    if (x+1 < m && !visited[x+1][y]) {
      blobSize += blob4(arr, visited, x+1, y, m, n);
    }
    if (y-1 >= 0 && !visited[x][y-1]) {
      blobSize += blob4(arr, visited, x, y-1, m, n);
    }
    if (y+1 < n && !visited[x][y+1]){
      blobSize += blob4(arr, visited, x, y+1, m, n);
    }

    return blobSize;
  }
}


int blob8(std::vector< std::vector< int > > &arr, std::vector< std::vector< bool > > &visited, int x, int y, int m, int n){

  int blobSize = 1;

  visited[x][y] = true;
  if (arr[x][y] == 0) {
    return 0;
  } else {
    //[x-1][y-1]
    if(x-1 >= 0 && y-1 >= 0 && !visited[x-1][y-1]){
      blobSize += blob8(arr, visited, x-1, y-1, m, n);
    }
    //[x-1][y]
    if(x-1 >= 0 && !visited[x-1][y]){
      blobSize += blob8(arr, visited, x-1, y, m, n);
    }
    //[x-1][y+1]
    if(x-1 >= 0 && y+1 < n && !visited[x-1][y+1]){
      blobSize += blob8(arr, visited, x-1, y+1, m, n);
    }
    //[x][y-1]
    if(y-1 >= 0 && !visited[x][y-1]){
      blobSize += blob8(arr, visited, x, y-1, m, n);
    }
    //[x][y+1]
    if(y+1 < n && !visited[x][y+1]){
      blobSize += blob8(arr, visited, x, y+1, m, n);
    }
    //[x+1][y-1]
    if(x+1 < m && y-1 >= 0 && !visited[x+1][y-1]){
      blobSize += blob8(arr, visited, x+1, y-1, m, n);
    }
    //[x+1][y]
    if(x+1 < m && !visited[x+1][y]){
      blobSize += blob8(arr, visited, x+1, y, m, n);
    }
    //[x+1][y+1]
    if(x+1 < m && y+1 <n && !visited[x+1][y+1]){
      blobSize += blob8(arr, visited, x+1, y+1, m, n);
    }
  }

  return blobSize;
}