struct point {
    double x, y;
    point(double _x, double _y) {
        x = _x;
        y = _y;
    }
};
struct line {
    double a, b, c;
};
line pointsToLine(point p1, point p2) {
    line l;
    if (fabs(p1.x - p2.x) < EPS)
        l.a = 1.0, l.b = 0.0, l.c = -p1.x;
    else {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;
        l.c = (double)(-l.a * p1.x) - p1.y;
    }
    re l;
}
bool areParallel(line l1, line l2) {
    return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS);
}
bool areSame(line l1, line l2) {
    return areParallel(l1, l2) && (fabs(l1.c - l2.c) < EPS);
}
bool areIntersect(line l1, line l2) {
    if (areSame(l1, l2)) re false;
    if (areParallel(l1, l2)) re false;
    re true;
}
point getIntersection(line l1, line l2) {
    point p(0.0, 0.0);
    p.x = (double)(l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    if (fabs(l1.b) > EPS)
        p.y = -(l1.a * p.x + l1.c);
    else
        p.y = -(l2.a * p.x + l2.c);
    re p;
}

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
