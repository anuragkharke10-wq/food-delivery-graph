# Food Delivery Route and Location Management System

A Data Structures & Algorithms case study (Case Study 19) that models a city's
food‑delivery network as a **graph** and explores routes using **BFS** and **DFS**.

## Problem

A delivery executive travels between restaurants, residential areas, and customer
locations. Each location connects to several others by roads. This program
represents those connections and lets you explore which locations are reachable
from any starting point.

## DSA concepts used

- Graph (vertices and edges)
- Adjacency list representation
- Breadth First Search (BFS)
- Depth First Search (DFS)

## Locations (vertices)

| ID | Location    | Type              |
|----|-------------|-------------------|
| 0  | Pizza Hut   | Restaurant        |
| 1  | Domino's    | Restaurant        |
| 2  | Palm Beach  | Residential area  |
| 3  | Sector 15   | Residential area  |
| 4  | Customer A  | Customer location |
| 5  | Customer B  | Customer location |

## Roads (edges)

Pizza Hut–Palm Beach, Pizza Hut–Domino's, Domino's–Sector 15, Palm Beach–Customer A,
Sector 15–Customer A, Sector 15–Customer B, Customer A–Customer B.

The graph is **undirected** — every road works both ways.

## How to compile and run

```bash
g++ food_delivery_graph.cpp -o food_delivery_graph
./food_delivery_graph
```

Then type a starting location (for example `PizzaHut`) when prompted.

## Sample output

```text
Adjacency List (connected locations):
PizzaHut -> PalmBeach  Dominos
Dominos -> PizzaHut  Sector15
PalmBeach -> PizzaHut  CustomerA
Sector15 -> Dominos  CustomerA  CustomerB
CustomerA -> PalmBeach  Sector15  CustomerB
CustomerB -> Sector15  CustomerA

Enter starting location: PizzaHut

BFS from PizzaHut: PizzaHut  PalmBeach  Dominos  CustomerA  Sector15  CustomerB
DFS from PizzaHut: PizzaHut  PalmBeach  CustomerA  Sector15  Dominos  CustomerB
```

## How it works

- **BFS** uses a **queue** (FIFO). It visits all immediate neighbours first, then
  their neighbours — exploring the network level by level. Good for finding the
  nearest location (fewest roads away).
- **DFS** uses **recursion** (a stack). It follows one route as deep as possible,
  then **backtracks** to try other branches. Good for checking if a route exists.
- **Connected locations** are found with a **visited array**: every location marked
  visited during a traversal is reachable from the start. If all vertices are
  visited, the network is fully connected.

## Files

- `food_delivery_graph.cpp` — source code
- `README.md` — this file

## Author

Anurag Kharke — B.Tech CSE (2025–29), ITM Skills University
