#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> read_matrix(int height, int width) {
    vector<vector<int>> matrix(height, vector<int>(width));
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }
    return matrix;
}

void print_matrix(vector<vector<int>> &matrix) {
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            if (j < matrix[i].size() - 1) {
                printf("%d ", matrix[i][j]);
            } else {
                printf("%d", matrix[i][j]);
            }
        }
        printf("\n");
    }
}

vector<vector<int>> apply_filter(vector<vector<int>> image, vector<vector<int>> kernel) {
    // swap kernel columns
    for (int i = 0; i < kernel.size(); ++i) {
        for (int j = 0; j < kernel[i].size() / 2; ++j) {
            swap(kernel[i][j], kernel[i][kernel[i].size() - j - 1]);
        }
    }

    // swap kernel rows
    for (int i = 0; i < kernel.size() / 2; ++i) {
        swap(kernel[i], kernel[kernel.size() - i - 1]);
    }

    // combine kernel with image
    vector<vector<int>> result(
                         image.size() - kernel.size() + 1,
                         vector<int>(image[0].size() - kernel[0].size() + 1, 0)
                     );
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            for (int k = 0; k < kernel.size(); ++k) {
                for (int p = 0; p < kernel[k].size(); ++p) {
                    result[i][j] += image[i + k][j + p] * kernel[k][p];
                }
            }
        }
    }
    return result;
}

int main() {
    int h, w, n, m;
    scanf("%d %d %d %d", &h, &w, &n, &m);
    auto image = read_matrix(h, w);
    auto kernel = read_matrix(n, m);
    auto result = apply_filter(image, kernel);
    print_matrix(result);
}
