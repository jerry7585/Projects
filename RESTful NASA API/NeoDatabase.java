/** NeoDatabase object is used to store NearEarthObject as well as freely change its contents which can be controlled in
 * NeoViewer
 *
 *
 * @author Jerry Su
 * 
 */


import big.data.DataSource;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.*;

public class NeoDatabase extends LinkedList<NearEarthObject> {
    public static final String API_KEY = "679CQaqwzXaAEfUIkE6ppvM1sa60kU7CI0VOd4c6";
    public static final String API_ROOT= "https://api.nasa.gov/neo/rest/v1/neo/browse?";

    /**default constructor
     * Postconditions:
     * The database has been constructed and is empty.
     */
    public NeoDatabase(){}

    /**Builds a query URL given a page number. This should be a simple method which returns
     * (API_ROOT + "page=" + pageNumber + "&api_key=" + API_KEY)
     *
     * Preconditions:
     * page greater than or equal to 0 and less than or equal to 715
     *
     * @param pageNumber
     * Integer ranging from 0 to 715 indicating the page the user wishes to load.
     * @return
     * string of url
     * @throws IllegalArgumentException
     * If pageNumber is not in the valid range.
     */
    public String buildQueryURL(int pageNumber) throws IllegalArgumentException{
        if (pageNumber >= 0 && pageNumber <= 715){
            return (API_ROOT + "page=" + pageNumber + "&api_key=" + API_KEY);
        } else {
            throw new IllegalArgumentException("pageNumber parameter out of bounds");
        }

    }

    /**Opens a connection to the data source indicated by queryURL and adds all NearEarthObjects found in the dataset.
     *
     * Preconditions:
     * queryURL is a non-null string representing a valid API request to the NASA NeoW service.
     *
     * Postconditions:
     * All NearEarthObject records returned have been added to the database, or else a IllegalArgumentException
     * has been thrown.
     *
     * @param queryURL
     * String containing the URL requesting a dataset from the NASA NeoW service
     * @throws IllegalArgumentException
     * If queryURL is null or cound not be resolved by the server.
     */
    public void addAll(String queryURL) throws IllegalArgumentException{
        if (queryURL == null){
            throw new IllegalArgumentException("Null queryURL");
        } else {
            DataSource ds = DataSource.connectJSON(queryURL);
            ds.load();
            if (ds.load().hasData()){
                NearEarthObject[] obj = ds.fetchArray(
                        "NearEarthObject",                    // Name of the class as a String.
                        "near_earth_objects/neo_reference_id",    // Identifier for constructor parameter 1 (initString).
                        "near_earth_objects/name",    // Identifier for constructor parameter 2 (initDouble).
                        "near_earth_objects/absolute_magnitude_h",  // Identifier for constructor parameter 3 (initTimestamp).
                        "near_earth_objects/estimated_diameter/kilometers/estimated_diameter_min",
                        "near_earth_objects/estimated_diameter/kilometers/estimated_diameter_max",
                        "near_earth_objects/is_potentially_hazardous_asteroid",
                        "near_earth_objects/close_approach_data/epoch_date_close_approach",
                        "near_earth_objects/close_approach_data/miss_distance/kilometers",
                        "near_earth_objects/close_approach_data/orbiting_body"
                );
                for (int i = 0; i < obj.length;i++){
                    this.add(obj[i]);
                }
            }
            else {
                throw new IllegalArgumentException();
            }
        }
    }

    /**Sorts the database using the specified Comparator of NearEarthObjects.
     *
     * Preconditions:
     * comp is not null.
     *
     * Postconditions:
     * The database has been sorted based on the order specified by the inidcated Comparator of NearEarthObjects.
     *
     * @param comp
     * Comparator of NearEarthObjects which will be used to sort the database. This parameter
     * can be any of the required Comparator classes listed above.
     * @throws IllegalArgumentException
     * If comp is null.
     */
    public void sort(Comparator comp) throws IllegalArgumentException{
        if (this.isEmpty()){

        } else if (comp == null){
            throw new IllegalArgumentException();
        } else {
            ArrayList<NearEarthObject> listObjects = new ArrayList<>();
            for (int i = 0; i < this.size(); i++){
                listObjects.add(this.get(i));
            }
            Collections.sort(listObjects, comp);
            for (int i = 0; i < listObjects.size(); i++){
                this.set(i,listObjects.get(i));
            }
        }
    }

    /**Displays the database in a neat, tabular form, listing all member variables for each NearEarthObject. Note
     *  the table should be printed in the order specified by the last sort() call.
     *
     *Preconditions:
     * This NeoDatabase is initialized and not null.
     *
     * Postconditions:
     * The table has been printed to the console but remains unchanged.
     */
    public void printTable(){
        String result = String.format("%15s %30s %15s %20s %15s %20s %20s %20s\n", "ID   |", "Name   |", "      Mag.      |",
                "    Diameter      |", "    Danger      | ", "     Close Date      |", "      Miss Dist      |", "  Orbits");
        String result2 = "==============================================================" +
                "=========================================================================================================\n";;
        SimpleDateFormat dateFormat = new SimpleDateFormat("mm-dd-yyyy");
        if (this.isEmpty()){

        } else {
            for (int i = 0; i < this.size(); i++){
                if (this.get(i).isDangerous()){
                    result2 += String.format("%15d %30s %15f %20f %15s %20s   %20f %20s\n",
                            this.get(i).getReferenceID(), this.get(i).getName(), this.get(i).getAbsoluteMagnitude(),
                            this.get(i).getAverageDiameter(), "true", dateFormat.format(this.get(i).getClosestApproachDate()),
                            this.get(i).getMissDistance(), this.get(i).getOrbitingBody());
                } else {
                    result2 += String.format("%15d %30s %15f %20f %15s %20s   %20f %20s\n",
                            this.get(i).getReferenceID(), this.get(i).getName(),this.get(i).getAbsoluteMagnitude(),
                            this.get(i).getAverageDiameter(), "false", dateFormat.format(this.get(i).getClosestApproachDate()),
                            this.get(i).getMissDistance(), this.get(i).getOrbitingBody());
                }
            }
        }
        System.out.println(result);
        System.out.println(result2);

    }

}