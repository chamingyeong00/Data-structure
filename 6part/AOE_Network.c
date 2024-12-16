Earliest Time

ai = edge<k, l>
early(i) = earliest[k]
late(i) = latest[l] - duration of ai;

earliest[j]
earliest[0] = 0
earliest[j] = max{earliest[i] + duration of <i, j>}
    for 모든 i (포함) {immediate predecessors of j}
if (earliset[k] < earliest[j] + ptr->duration)
    earliest[k] = earliest[j] + ptr->duration

Latest Times
latest[n-1] = earliest[n-1]
latest[j] = min{latest[i] - duration of <j, i>}
    for 모든 i (포함) {immediate successors of j}
if (latest[k] > latest[j] - ptr->duration)
    latest[k] = latest[j] = ptr->duration