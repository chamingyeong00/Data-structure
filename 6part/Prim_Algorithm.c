T = {};
TV = {0};
while (T contains fewer than n-1 edges){
    let (u, v) be a least cost edge such that
        u <= TV and v !<= TV;
    if (there is no such edge)
        break;
    add v to TV;
    add (u, v) to T;
}

if (T contains fewer than n-1 edges)
    printf("No spanning tree\n");