double separateSquares(int** squares, int squaresSize, int* squaresColSize) {
    double totalArea = 0.0;
    double low = 1e9, high = -1e9;

    // Compute total area and search bounds
    for (int i = 0; i < squaresSize; i++) {
        double y = squares[i][1];
        double l = squares[i][2];
        totalArea += l * l;
        if (y < low) low = y;
        if (y + l > high) high = y + l;
    }

    double half = totalArea / 2.0;

    // Binary search for y
    for (int iter = 0; iter < 100; iter++) {
        double mid = (low + high) / 2.0;
        double areaBelow = 0.0;

        for (int i = 0; i < squaresSize; i++) {
            double y = squares[i][1];
            double l = squares[i][2];

            if (mid > y) {
                double height = mid - y;
                if (height > l) height = l;
                areaBelow += height * l;
            }
        }

        if (areaBelow < half)
            low = mid;
        else
            high = mid;
    }

    return (low + high) / 2.0;
}
