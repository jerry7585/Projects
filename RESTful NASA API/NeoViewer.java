/** NeoViewer is used to change NeoDatabase contents according to user inputs
 *
 *
 *
 * @author Jerry Su
 */

import org.apache.commons.net.nntp.NewGroupsOrNewsQuery;

import java.util.*;
public class NeoViewer {

    public static void main(String [] args){
        Scanner in = new Scanner(System.in);
        char ans = '-';
        System.out.println("Welcome to NEO Viewer!\n");
        NeoDatabase dataBase = new NeoDatabase();
        while (ans != 'q' || ans != 'Q'){
            System.out.println("Option Menu:");
            System.out.println("A) Add a page to the database");
            System.out.println("S) Sort the database ");
            System.out.println("P) Print the database as a table.");
            System.out.println("Q) Quit");
            ans = in.next().charAt(0);
            switch(Character.toLowerCase(ans)){
                case 'a':
                    System.out.println("Enter the page to load:");
                    int page = in.nextInt();
                    try {
                        dataBase.addAll(dataBase.buildQueryURL(page));
                    } catch(Exception e){
                        System.out.println("Error caught based on input");
                    }
                    System.out.println("Page loaded successfully!");
                    break;
                case 's':
                    System.out.println("R) Sort by referenceID");
                    System.out.println("D) Sort by diameter");
                    System.out.println("A) Sort by approach date");
                    System.out.println("M) Sort by miss distance");
                    char oper = in.next().charAt(0);
                    switch (Character.toLowerCase(oper)){
                        case 'r':
                            ReferenceIDComparator reference = new ReferenceIDComparator();
                            dataBase.sort(reference);
                            break;
                        case 'd':
                            DiameterComparator diameter = new DiameterComparator();
                            dataBase.sort(diameter);
                            break;
                        case 'a':
                            ApproachDateComparator approach = new ApproachDateComparator();
                            dataBase.sort(approach);
                            break;
                        case 'm':
                            MissDistanceComparator missDist= new MissDistanceComparator();
                            dataBase.sort(missDist);
                            break;
                        default:
                            System.out.println("invalid sort choice");
                            break;

                    }
                    break;
                case'p':
                    dataBase.printTable();
                    break;
                case'q':
                    System.exit(1);
                    break;
                default:
                    System.out.println("Invalid input"); break;
            }
        }
    }
}