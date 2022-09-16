/** NearEarthObject is used to create each individual asteroid found through NASA API, and stored in NeoDatabase
 *
 *
 * @author Jerry Su
 * 
 */


import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;

public class NearEarthObject {
    private int referenceID;
    private String name;
    private double absoluteMagnitude;
    private double averageDiameter;
    private boolean isDangerous;
    private Date closestApproachDate;
    private double missDistance;
    private String orbitingBody;

    /**default constructor
     *
     * @param referenceID
     * Unique the ID of the NEO.
     * Fetched using the "near_earth_objects/neo_reference_id" identifier.
     * @param name
     * Unique name of the asteroid or orbital body.
     * Fetched using the "near_earth_objects/name" identifier.
     * @param absoluteMagnitude
     * Absolute brightness of the asteroid or orbital body in the sky.
     * Fetched using the "near_earth_objects/absolute_magnitude_h" identifier.
     * @param minDiameter
     * Estimated minimum diameter of the asteroid or orbital body in kilometers. This parameter should be used in conjunction with the maxDiameter parameter to calculate and initialize the averageDiameter member variable.
     * Fetched using the "near_earth_objects/estimated_diameter/kilometers/estimated_diameter_min" identifier.
     * @param maxDiameter
     * Estimated maximum diameter of the asteroid or orbital body in kilometers. This parameter should be used in conjunction with the minDiameter parameter to calculate and initialize the averageDiameter member variable.
     * Fetched using the "near_earth_objects/estimated_diameter/kilometers/estimated_diameter_max" identifier.
     * @param isDangerous
     * Boolean value indicating whether the astroid or orbital body is a potential impact threat.
     * Fetched using the "near_earth_objects/is_potentially_hazardous_asteroid" identifier.
     * @param closestDateTimestamp
     * Unix timestamp representing the date of closest approach. Note that this can be used to directly construct the closestApproachDate member variable, as the Date class provides a constructor taking a timestamp as a parameter.
     * Fetched using the "near_earth_objects/close_approach_data/epoch_date_close_approach" identifier.
     *
     * @param missDistance
     * Distance in kilometers at which the asteroid or orbital body will pass by the Earth on the date of it's closest approach.
     * Fetched using the "near_earth_objects/close_approach_data/miss_distance/kilometers" identifier.
     * @param orbitingBody
     * Planet or other orbital body which this NEO orbits.
     * Fetched using the "near_earth_objects/close_approach_data/orbiting_body" identifier.
     *
     */
    public NearEarthObject(int referenceID, String name, double absoluteMagnitude, double minDiameter
            , double maxDiameter, boolean isDangerous, long closestDateTimestamp,
                           double missDistance, String orbitingBody){
        this.referenceID = referenceID;
        this.name = name;
        this.absoluteMagnitude = absoluteMagnitude;
        this.averageDiameter = (maxDiameter + minDiameter)/2;
        this.isDangerous = isDangerous;
        this.closestApproachDate = new Date(closestDateTimestamp);
        this.missDistance = missDistance;
        this.orbitingBody = orbitingBody;
    }

    /**setter function for reference ID
     *
     * @param referenceID
     * the reference id that object is set to
     */
    public void setReferenceID(int referenceID) {
        this.referenceID = referenceID;
    }

    /**setter function for name
     *
     * @param name
     * the name the object is set to
     */
    public void setName(String name) {
        this.name = name;
    }

    /**Setter function for absolute Magnitude
     *
     * @param absoluteMagnitude
     * the absolute magnitude the object is set to
     */
    public void setAbsoluteMagnitude(double absoluteMagnitude) {
        this.absoluteMagnitude = absoluteMagnitude;
    }

    /**setter for average diameter
     *
     * @param averageDiameter
     * the average diameter the object is set to
     */
    public void setAverageDiameter(double averageDiameter) {
        this.averageDiameter = averageDiameter;
    }

    /**setter function for isDangerous
     *
     * @param dangerous
     * sets dangerous to object's isDangerous variable
     */
    public void setDangerous(boolean dangerous) {
        isDangerous = dangerous;
    }

    /**setter function for closest approach date
     *
     * @param closestApproachDate
     * the closest approach date the object is set to
     */
    public void setClosestApproachDate(Date closestApproachDate) {
        this.closestApproachDate = closestApproachDate;
    }

    /**setter function for miss distance
     *
     * @param missDistance
     * the miss distance the object is set to
     */
    public void setMissDistance(double missDistance) {
        this.missDistance = missDistance;
    }

    /**setter function for orbiting body
     *
     * @param orbitingBody
     * the orbiting body the object is set to
     */
    public void setOrbitingBody(String orbitingBody) {
        this.orbitingBody = orbitingBody;
    }

    /**getter function for referenceID
     *
     * @return
     * returns referenceID of object
     */
    public int getReferenceID() {
        return referenceID;
    }

    /**getter function for name
     *
     * @return
     * returns name of object
     */
    public String getName() {
        return name;
    }

    /**getter function for absolute magnitude
     *
     * @return
     * returns absolute magnitude of object
     */
    public double getAbsoluteMagnitude() {
        return absoluteMagnitude;
    }

    /**getter function for average diameter
     *
     * @return
     * returns the average diameter of the object
     */
    public double getAverageDiameter() {
        return averageDiameter;
    }

    /**getter function for isDangerous
     *
     * @return
     * returns true if it is dangerous, false otherwise
     */
    public boolean isDangerous() {
        return isDangerous;
    }

    /**getter function for closest approach date
     *
     * @return
     * returns the closest approach date of the object
     */
    public Date getClosestApproachDate() {
        return closestApproachDate;
    }

    /**getter function for miss distance
     *
     * @return
     * returns the miss distance of the object
     */
    public double getMissDistance() {
        return missDistance;
    }

    /**getter function for orbiting body
     *
     * @return
     * returns the name of the orbiting body of the object
     */
    public String getOrbitingBody() {
        return orbitingBody;
    }


}