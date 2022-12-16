import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;

import javax.swing.JFrame;


import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartPanel;
import org.jfree.chart.JFreeChart;
import org.jfree.chart.plot.XYPlot;
import org.jfree.data.time.Second;
import org.jfree.data.time.TimeSeries;
import org.jfree.data.time.TimeSeriesCollection;
import org.jfree.ui.ApplicationFrame;

import org.json.JSONObject;

public class Main {
    public static final String PriceURL = "https://api.coindesk.com/v1/bpi/currentprice/BTC.json";
    public static final int rate = 5000; //milliseconds for refresh rate
    public static void main(String[] args) throws Exception {
        System.out.println("The program is now running...");
        while (true) {
            // * Make an HTTP GET request to the CoinDesk API to get the current BTC price
            URL url = new URL(PriceURL);
            HttpURLConnection con = (HttpURLConnection) url.openConnection();
            con.setRequestMethod("GET");

            // * Response from the API
            // ? reads until there is no more new lines in the response
            BufferedReader in = new BufferedReader(new InputStreamReader(con.getInputStream()));
            String inputLine;
            StringBuffer content = new StringBuffer();
            while ((inputLine = in.readLine()) != null) {
                content.append(inputLine);
            }
            in.close();
            con.disconnect();

            // * Parse the JSON response and set price to btcPrice
            JSONObject obj = new JSONObject(content.toString());
            double btcPrice = obj.getJSONObject("bpi").getJSONObject("USD").getDouble("rate_float");

            // * Print the BTC price to the console make sure to use only 2 decimal points using string format
            String newBtcPrice = String.format("%.2f", btcPrice);
            System.out.println("Current BTC price: $" + newBtcPrice);
            
            JFrame frame = new JFrame();
            frame.setSize(800, 600);
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame.setVisible(true);

            TimeSeries series = new TimeSeries("Bitcoin Price (USD)");
            TimeSeriesCollection dataset = new TimeSeriesCollection(series);

            // ? Wait for 5 seconds before updating
            Thread.sleep(rate);
        }
    }
}