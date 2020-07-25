// compare result between 2 double numbers
int comp_double(double a, double b) {
	if (fabs(a - b) <= 1e-3) {
		return 0; // equal
	}
	return (a < b) ? -1 : 1;
}

// get distance between 2 points
double distance(double x1, double y1, double x2, double y2) { 
	return hypot(fabs(x1 - x2), fabs(y1 - y2)); 
}
