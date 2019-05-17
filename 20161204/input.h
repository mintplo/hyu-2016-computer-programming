using namespace std;

class input {
	public:
		void one(int size, double* arr, ifstream* ifs) {
			for (int i = 0; i < size; i++) {
				*ifs>>arr[i];
			}
		}
		void two(int row, int col, double** arr, ifstream* ifs) {
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					*ifs>>arr[i][j];
				}
			}
		}
};