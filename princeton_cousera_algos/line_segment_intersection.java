/**
 * 2d orthogonal line segment intersection: sweep line algorithm reduces to
 *   1d range search, can extend to be used in Rectangle Intersection
 *
 *   Sweep vertical line from left to right
 *     x-coordinates define events
 *     h-segment (left endpoint): insert y-coordinate into BST
 *     h-segment (right endpoint): remove y-coordinate from BST
 *     v-segment: range serach for interval of y-endpoints
 */

