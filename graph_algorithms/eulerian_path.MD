# Eulerian Path

- A path of edges that visits every **edge** in a graph **exactly once**.
- Not all graphs have a eulerian path.
- Choice of starting node of the path is important.
- All nodes with non-zero degree (that means koi edge to hai is node se) **must** belong to a single connected component, else euler path is impossible bhai.

## Eulerian Circuit

- A Eulerian Path which starts and end on the same node.
- Also known as **Eulerian Cycle**.
- If your graph has Eulerian Cycle, you can start your path/circuit from any node.
- If your graph does not have Eulerian Cycle, then either you _wont_ be able to return to start node, OR you will not be able to visit all edges.

### If ALL nodes have even degree, then Eulerian Circuit will definely exist.

Intution is ek node mai kisi edge se enter kiya to dusri edge se bahar bhi nikal payenge na.

## Eulerian Graph

- A graph which contains a Eulerian Circuit (and so obviously a Euler path as well).
- A semi eulerian graph only contains a Euler Path, not a circuit.
- **So in a semi eulerian graph, we wont be able to return to start node after visiting each edge exactly once. The start and end node of a Euler path (which aint a circuit) will have ODD degrees. Rest all nodes will have even degree.**
- Basic idea is ki yahi dono nodes se nikalke vapas nahi aa sake ya fir vapas nahi nikal sake.
