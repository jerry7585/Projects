/** DiameterComparator implements comparator class for NEarEarthObjects so it can be used to sort
 * objects by average diameter values
 *
 *
 * @author Jerry Su
 * 
 */

public class DiameterComparator implements java.util.Comparator<NearEarthObject> {
    public int compare(NearEarthObject left, NearEarthObject right) {
        if (left.getAverageDiameter() > right.getAverageDiameter()) {
            return 1;
        } else if (left.getAverageDiameter() == right.getAverageDiameter()) {
            return 0;
        } else {
            return -1;
        }
    }
}