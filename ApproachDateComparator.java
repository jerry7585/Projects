/** ApproachDateComparator implements comparator class for NEarEarthObjects so it can be used to sort
 * objects by approach date values
 *
 *
 * @author Jerry Su 
 * 
 */

public class ApproachDateComparator implements java.util.Comparator<NearEarthObject> {
    public int compare(NearEarthObject left, NearEarthObject right) {
        if (left.getClosestApproachDate().compareTo(right.getClosestApproachDate()) == 1 ) {
            return 1;
        } else if (left.getClosestApproachDate().compareTo(right.getClosestApproachDate()) == 0) {
            return 0;
        } else {
            return -1;
        }
    }
}