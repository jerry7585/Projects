/** MissDistanceComparator implements comparator class for NEarEarthObjects so it can be used to sort
 * objects by miss distance values
 *
 *
 * @author Jerry Su
 * 
 */

public class MissDistanceComparator implements java.util.Comparator<NearEarthObject> {
    public int compare(NearEarthObject left, NearEarthObject right) {
        if (left.getMissDistance() > right.getMissDistance()) {
            return 1;
        } else if (left.getMissDistance() == right.getMissDistance()) {
            return 0;
        } else {
            return -1;
        }
    }
}