#pragma once

#include <vector>

enum PointInPolyResult {IN, ON, OUT};

/**
 * Determines if a point lies inside, outside or on a polygon. The polygon
 * is determined by its vertices.
 */
PointInPolyResult pointinpoly(std::pair<int, int> p, const std::vector<std::pair<int, int>> &poly);

