package stubs;
import java.io.IOException; 
import org.apache.hadoop.io.Text;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.mapreduce.Mapper; 
import org.apache.hadoop.mapreduce.lib.input.FileSplit;
import org.apache.hadoop.fs.Path;

public class TFIDFMapper extends Mapper<LongWritable, Text , Text, IntWritable>{
	@Override
	public void map(LongWritable key, Text value, Context context) 
		throws IOException, InterruptedException{
			
			
			/*
			 * Get the FileSplit for the input file, which provides access to the file's path. 
			 * You need the file's path because it contains the name of the play.
			 */
			FileSplit fileSplit = (FileSplit)context.getInputSplit();
			Path path = fileSplit.getPath();
			
			/*
			 * call the getName method on the Path object to retrieve the file's name,
			 * which is the name of the play. Then append "@" and the line number to 
			 * the play's name. The resulting string is the location of the words
			 * on that line.
			 */
			String docid = path.getName();
			
			String line = value.toString();
			for (String word: line.split("\\W+")) {
				if(word.matches("^[a-zA-Z]+$")) {
					word = word.toLowerCase();
					context.write(new Text(word + "@" + docid), new IntWritable(1));
					
				}
			}
		}
	}
	
