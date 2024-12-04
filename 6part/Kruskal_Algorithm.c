T = {};
while (T contains less than n-2 edges && E is not empty){
    choose the least cost edge (v, w) from E;
    delete (v, w) frome E;
    if ((v, w) dose not create a cycle in T)
        add (v, w) to T;
    else
        discard(v, w);
}

if (T contains fewer than n-1 edges)
    printf("No spanning tree\n");