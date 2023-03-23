#include "astar.hxx"
#include "model.hxx"

AStar::AStar(Position start, Position end, std::unordered_map<Position, bool,
             ArrayHasher> wM)
{
    // creating the open and closed sets
    std::vector<Node> openSet;
    std::vector<Node> closedSet;

    // creating a vector to check the neighbors
    std::vector<Position> neighbors = {Position(-1,0), Position(1,0),
                                       Position(0,-1), Position(0,1)};

    // adding the starting position to the open set
    Node startingNode = Node(start, start, end);
    startingNode.parent = start;
    openSet.push_back(startingNode);

    // checking if already at the dest
    if(startingNode.p == end){
        path.push_back(startingNode);
        return;
    }

    int counter = 0;

    while(true){
        // removes the lowest fCost and returns that node
        Node current = removeLowestFCost(openSet);

        // add to closed
        closedSet.push_back(current);

        // checking if the path has been found
        if(current.p == end){
            // retracing steps to get the path
            while(current.p != startingNode.p){
                path.push_back(current);
                for(Node n : closedSet){
                    if(current.parent == n.p){
                        current = n;
                        break;
                    }
                }
            }
            break;
        }

        counter++;
        if(counter > 200){
            path.push_back(startingNode);
            std::cout << "AStar not working\n";
            break;
        }

        for(Position dir : neighbors){
            Node neighbor = Node({dir.x*grid_size + current.p.x,
                                 dir.y*grid_size + current.p.y});

            // checking if the position of the new node is valid or is already
            // in the closed list
            if(wM[neighbor.p] ||
                std::find(closedSet.begin(), closedSet.end(), neighbor) !=
                closedSet.end()){
                continue;
            }

            // if path is shorter or not in open
            int newMovementCost = current.gCost + getDist(current, neighbor.p);
            if(newMovementCost < neighbor.gCost || std::find(openSet.begin(),
                         openSet.end(), neighbor) == openSet.end()){

                // get fCost
                neighbor.gCost = newMovementCost;
                neighbor.hCost = getDist(neighbor, end);

                // set parent of neighbor to current
                neighbor.parent = current.p;

                // if not in open add to open
                if(std::find(openSet.begin(),
                             openSet.end(), neighbor) == openSet.end()){
                    openSet.push_back(neighbor);
                }
            }


        }

    }
}

Node AStar::removeLowestFCost(std::vector<Node>& os)
{
    // finding the node with the lowest fCost
    Node current_space = Node();
    for(Node& node : os){
        if(node.fCost() < current_space.fCost()){
            current_space = node;
        }
    }
    Node current = Node(current_space.p, current_space.gCost,
                        current_space.hCost, current_space.parent);

    // remove from open
    for(Node& curr_node : os){
        if(current.p == curr_node.p){
            curr_node = os.back();
            os.pop_back();
            return current;
        }
    }

    return current;
}

int AStar::get_direction() const
{
    // left = 1, right = 2, down = 3, up = 4
    Position next = path.back().p;
    Position start = path.back().parent;

    if(next.x - start.x < 0){
        return 1;
    }else if(next.x - start.x > 0){
        return 2;
    }else if(next.y - start.y < 0){
        return 3;
    }else if(next.y - start.y > 0){
        return 4;
    }else{
        return 0;
    }
}