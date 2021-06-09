struct point{
    double x, y;
};
double distance(point A, point B){
    double dx = A.x-B.x, dy = A.y-B.y;
    return sqrt(dx*dx+dy*dy);
}
double cross(point A, point B, point C){
    double ux = C.x-A.x, uy = C.y-A.y;
    double vx = B.x-A.x, vy = B.y-A.y;
    return ux*vy-uy*vx;
}
double dot(point A, point B, point C){ // AB dot BC
    double ux = B.x-A.x, uy = B.y-A.y;
    double vx = C.x-B.x, vy = C.y-B.y;
    return ux*vx+uy*vy;
}
double distLinePoint(point A, point B, point C){ // AB to C
    if(A.x == B.x && A.y == B.y)return distance(C, A);
    double dist = fabs(cross(A, B, C)/distance(A, B));
    double dot1 = dot(A, B, C);
    if(dot1 > 0)return distance(B, C);
    double dot2 = dot(B, A, C);
    if(dot2 > 0)return distance(A, C);
    return abs(dist);
}
