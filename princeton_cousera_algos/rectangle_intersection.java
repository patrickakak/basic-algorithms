/**
 * 2d orthogonal rectangle intersection search, 
 * sweep line reduces to 1d interval serach:
 *
 *   Sweep vertical line from left to right
 *     x-coordinates of left and right endpoints define events
 *     Maintain set of rectangles that intersect the sweep line in an 
 *       interval serach tree (using y-intervals of rectangle)
 *     Left endpoint: interval search for y-interval of rectangle;
 *       insert y-interval
 *     Right endpoint: remove y-interval
 */
