class make_array {
	public:
		double* one(int a) {
			double* b = new double[a];
			return b;
		}
		double** two(int a, int b) {
			double** c = new double* [a];
			for (int i = 0; i < a; i++) {
				c[i] = new double[b];
			}

			return c;
		}
};