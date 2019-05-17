class print {
	public:
		void one(int a, double *b) {
			for(int i = 0; i < a; i++) {
				std::cout<<b[i]<<'\n';
			}
		}
		void two(int a, int b, double** c) {
			for (int i = 0; i < a; i++) {
				for (int j = 0; j < b; j++) {
					std::cout<<c[i][j]<<'\t';
				}
				std::cout<<'\n';
			}
		}
};