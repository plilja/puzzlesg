#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Plant {
    int x,
        y,
        flies,
        energy;
    Plant *pre = 0;

    bool operator<(const Plant &p) const {
        if (x == p.x) {
            return y < p.y;
        } else {
            return x < p.x;
        }
    }
};

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    // Read input
    vector<Plant> unfiltered_plants;
    for (int i = 0; i < n; ++i) {
        int x, y, f;
        scanf("%d %d %d", &x, &y, &f);
        Plant p;
        p.x = x;
        p.y = y;
        p.flies = f;
        p.energy = 0;
        unfiltered_plants.push_back(p);
    }

    // Remove plants that are definately unreachable
    vector<Plant> plants;
    for (int i = 0; i < n; ++i) {
        auto unfiltered_plant = unfiltered_plants[i];
        int x = unfiltered_plant.x,
            y = unfiltered_plant.y,
            f = unfiltered_plant.flies;
        if (x >= unfiltered_plants[0].x && 
                y >= unfiltered_plants[0].y && 
                x <= unfiltered_plants[n - 1].x && 
                y <= unfiltered_plants[n - 1].y) {
            Plant p;
            p.x = x;
            p.y = y;
            p.flies = f;
            p.energy = 0;
            plants.push_back(p);
        }
    }

    Plant &start = plants[0],
          &end = plants[plants.size() - 1];

    sort(plants.begin(), plants.end());

    map<int, Plant*> best_x, 
                    best_y;

    // Perform dynprog algo
    plants[0].energy = plants[0].flies;
    best_x[start.x] = &plants[0];
    best_y[start.y] = &plants[0];
    for (int i = 1; i < plants.size(); ++i) {
        auto &plant = plants[i];
        auto it1 = best_x.find(plant.x);
        if (it1 != best_x.end() && it1->second->energy >= k) {
            plant.energy = it1->second->energy - k + plant.flies;
            plant.pre = it1->second;
        }
        auto it2 = best_y.find(plant.y);
        if (it2 != best_y.end() && it2->second->energy >= k) {
            if (it1 == best_x.end() || it1->second->energy < it2->second->energy) {
                plant.energy = it2->second->energy - k + plant.flies;
                plant.pre = it2->second;
            }
        }
        if (it1 == best_x.end() || plant.energy > it1->second->energy) {
            best_x[plant.x] = &plant;
        }
        if (it2 == best_y.end() || plant.energy > it2->second->energy) {
            best_y[plant.y] = &plant;
        }
    }

    // Backtrack from end to find path
    vector<Plant> path;
    Plant *p = &end;
    while (p != 0) {
        path.push_back(*p);
        p = p->pre;
    }
    reverse(path.begin(), path.end());

    // Output answer
    printf("%d\n", end.energy);
    printf("%lu\n", path.size());
    for (Plant plant : path) {
        printf("%d %d\n", plant.x, plant.y);
    }
}
