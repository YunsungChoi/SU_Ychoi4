package stubs;

import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Reducer;


public class TFIDFReducer2 extends Reducer<Text, Text, Text, Text>{
	
	@Override
	public void reduce(Text key, Iterable<Text> values, Context context)
			throws IOException, InterruptedException {
		
		int totalCount = 0;
		Map<String, Integer> termCounts = new HashMap<>();
	
		for (Text value : values) {
			String[] inputValues = value.toString().split("@");
			if (inputValues.length == 2) {
				String term = inputValues[0];
				int count = Integer.parseInt(inputValues[1]);
				totalCount += count;
				termCounts.put(term, count);
			}
		}
		
		for (Map.Entry<String, Integer> entry : termCounts.entrySet()) {
			String term = entry.getKey();
			int count = entry.getValue();
			context.write(new Text(term + "@" + key), new Text(count + "@" + totalCount));
		}
	}
}


