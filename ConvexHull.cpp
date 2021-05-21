struct pt{
    double x, y;
};
double dis(pt a, pt b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool cmp(const pt& a, const pt& b){
    if(a.x == b.x)return a.y < b.y;
    return a.x < b.x;
}
bool cw(pt a, pt b, pt c){ // if a, b, c are in a clockwise order
    return ((b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x)) > 0;
}
bool ccw(pt a, pt b, pt c){ // if a, b, c are in a counterclockwise order
    return ((b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x)) < 0;
}
vector<pt> convex_hull(vector<pt> v){
    assert(v.size() > 1);
    sort(all(v), cmp);
    pt left_most = v[0], right_most = v.back();
    vector<pt> up, down, out;
    up.pb(left_most);
    down.pb(left_most);
    for(int i = 1; i < (int)v.size(); i++){
        if(i == (int)v.size()-1 || cw(left_most, v[i], right_most)){
            while((int)up.size() >= 2 && !cw(up[(int)up.size()-2], up[(int)up.size()-1], v[i])){
                up.pop_back();
            }
            up.pb(v[i]);
        }
        if(i == (int)v.size()-1 || ccw(left_most, v[i], right_most)){
            while((int)down.size() >= 2 && !ccw(down[(int)down.size()-2], down[(int)down.size()-1], v[i])){
                down.pop_back();
            }
            down.pb(v[i]);
        }
    }
    for(int i = 0; i < (int)up.size(); i++)out.pb(up[i]);
    for(int i = (int)down.size()-2; i >= 1; i--)out.pb(down[i]);
    return out;
}
