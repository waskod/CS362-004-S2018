
import junit.framework.TestCase;
import org.junit.Test;

public class UrlValidatorTest extends TestCase 
{

	public UrlValidatorTest(String testName) 
	{
		super(testName);
	}

	public void testManualTest() 
	{

		UrlValidator urlTest = new UrlValidator();

		System.out.println("\n==================== Manual Section ====================\n");
		System.out.println("URL tests: \n");

		// Checking a valid URL
		System.out.println("Checking http://foo.bar.com/");
		System.out.println(urlTest.isValid("http://foo.bar.com/")+"\n");

		// checking invalid URLS
		System.out.println("Checking abcdefghijk");
		System.out.println(urlTest.isValid("abcdefghijk")+"\n");

		System.out.println("Checking http://256.256.256.256/");
		System.out.println(urlTest.isValid("http://256.256.256.256/")+"\n");


		// Checking the scheme
		System.out.println("Scheme test:");
		// http should work
		System.out.println(urlTest.isValidScheme("http")+"\n");
		// this returns false when it should return true.
		// must be a bug inside isValidScheme
		//


		// Checking the path
		System.out.println("Path test:");
		System.out.println(urlTest.isValidPath("/")+"\n");


		// Checkign the fragment
		System.out.println("Fragment test:");
		System.out.println(urlTest.isValidFragment("")+"\n");


		// Checking the authority
		System.out.println("Authority test:");
		// This Test contains an error
		//System.out.println(urlTest.isValidAuthority("foo.bar.com")+"\n");
		
		
		System.out.println("Testing Port Numbers:");
		System.out.println("Testing URL: \"http://www.google.com\"");
		System.out.println(urlTest.isValid("http://www.google.com/")+"\n");
		
		System.out.println("Testing URL: \"http://www.google.com:80\"");
		System.out.println(urlTest.isValid("http://www.google.com:80")+"\n");
		
		System.out.println("Testing URL: \"http://www.google.com:200\"");
		System.out.println(urlTest.isValid("http://www.google.com:200")+"\n");
		
		System.out.println("Testing URL: \"http://www.google.com:1000\"");
		System.out.println(urlTest.isValid("http://www.google.com:1000")+"\n");
		
		System.out.println("Testing URL: \"http://www.google.com:\"");
		System.out.println(urlTest.isValid("http://www.google.com:")+"\n");
		
		System.out.println("Testing URL: \"http://www.google.com:100000000000000000\"");
		System.out.println(urlTest.isValid("http://www.google.com:100000000000000000")+"\n");
		
		System.out.println("Testing URL: \"http://www.google.com:-80\"");
		System.out.println(urlTest.isValid("http://www.google.com:-80")+"\n");
		
		System.out.println("\n==================== END Manual Section ====================\n");
	}

	@Test
	public void testYourFirstPartition() 
	{
		System.out.println("\n==================== First Partition ====================\n");
		
		System.out.println("Testing Scheme Partition...\n");
		String[] schemeSet = { " ", "http://", "://" };
		String currentScheme;
		
		UrlValidator schemeVal = new UrlValidator(schemeSet, 0);
				
		// testing scheme 1
		currentScheme = schemeSet[0];
		System.out.println("Testing scheme: \"" + currentScheme + "\" \n");
		boolean schemeResult = schemeVal.isValidScheme(currentScheme);
		if(schemeResult == true)
			System.out.println("TEST FAILURE\n");
		else
			System.out.println("TEST SUCCESS\n");
		
		// testing scheme 2
		currentScheme = schemeSet[1];
		System.out.println("Testing scheme: \"" + currentScheme + "\" \n");
		schemeResult = schemeVal.isValidScheme(currentScheme);
		if(schemeResult == false)
			System.out.println("TEST FAILURE\n");
		else
			System.out.println("TEST SUCCESS\n");
		
		// testing scheme 3
		currentScheme = schemeSet[2];
		System.out.println("Testing scheme: \"" + currentScheme + "\" \n");
		schemeResult = schemeVal.isValidScheme(currentScheme);
		if(schemeResult == true)
			System.out.println("TEST FAILURE\n");
		else
			System.out.println("TEST SUCCESS\n");
		
		
		
		
		System.out.println("\n==================== END First Partition ====================\n");
	}

	@Test
	public void testYourSecondPartition() 
	{
		System.out.println("\n==================== Second Partition ====================\n");
		
		System.out.println("Testing Authority Partition...\n");
		
		String[] authSet = { " ", "www.google.com", "www.google" };
		UrlValidator authVal = new UrlValidator(authSet, 0);
		boolean authorityResult;
		String currentAuth;
		
		currentAuth = authSet[0];
		System.out.println("Testing Authority \"" + currentAuth + "\"\n");
		authorityResult = authVal.isValidAuthority(currentAuth); // This Test contains an error
		if(authorityResult == true)
			System.out.println("TEST FAILURE\n");
		else
			System.out.println("TEST SUCCESS\n");
		
		currentAuth = authSet[1];
		System.out.println("Testing Authority \"" + currentAuth + "\"\n");
		authorityResult = authVal.isValidAuthority(currentAuth); // This Test contains an error
		if(authorityResult == false)
			System.out.println("TEST FAILURE\n");
		else
			System.out.println("TEST SUCCESS\n");
		
		currentAuth = authSet[2];
		System.out.println("Testing Authority \"" + currentAuth + "\"\n");
		authorityResult = authVal.isValidAuthority(currentAuth); // This Test contains an error
		if(authorityResult == true)
			System.out.println("TEST FAILURE\n");
		else
			System.out.println("TEST SUCCESS\n");
		
		
		
		System.out.println("\n==================== END Second Partition ====================\n");
	}

	@Test
	public void testYourThirdPartition() 
	{
		System.out.println("\n==================== Third Partition ====================\n");
		
		System.out.println("\nTest Port Partition\n");
		String[] portSet = { "www.google.com:5", "www.google.com:50", "www.google.com:500", "www.google.com:5000",
				"www.google.com:50000", "www.google.com:", "www.google.com:50~", };
		
		UrlValidator portVal = new UrlValidator(portSet, 0);
		String currentPort;
		boolean portRes;
		
		
		currentPort = portSet[0];
		System.out.println("Testing Port \"" + currentPort + "\"\n");
		portRes = portVal.isValidAuthority(currentPort); // This Test contains an error
		if(portRes == false)
			System.out.println("TEST FAILURE\n");
		else
			System.out.println("TEST SUCCESS\n");
		
		
		
		currentPort = portSet[1];
		System.out.println("Testing Port \"" + currentPort + "\"\n");
		portRes = portVal.isValidAuthority(currentPort); // This Test contains an error
		if(portRes == false)
			System.out.println("TEST FAILURE\n");
		else
			System.out.println("TEST SUCCESS\n");
		
		
		
		currentPort = portSet[2];
		System.out.println("Testing Port \"" + currentPort + "\"\n");
		portRes = portVal.isValidAuthority(currentPort); // This Test contains an error
		if(portRes == false)
			System.out.println("TEST FAILURE\n");
		else
			System.out.println("TEST SUCCESS\n");
		
		
		currentPort = portSet[3];
		System.out.println("Testing Port \"" + currentPort + "\"\n");
		portRes = portVal.isValidAuthority(currentPort); // This Test contains an error
		if(portRes == false)
			System.out.println("TEST FAILURE\n");
		else
			System.out.println("TEST SUCCESS\n");
		
		
		
		currentPort = portSet[4];
		System.out.println("Testing Port \"" + currentPort + "\"\n");
		portRes = portVal.isValidAuthority(currentPort); // This Test contains an error
		if(portRes == true)
			System.out.println("TEST FAILURE\n");
		else
			System.out.println("TEST SUCCESS\n");
		
		
		
		currentPort = portSet[5];
		System.out.println("Testing Port \"" + currentPort + "\"\n");
		portRes = portVal.isValidAuthority(currentPort); // This Test contains an error
		if(portRes == true)
			System.out.println("TEST FAILURE\n");
		else
			System.out.println("TEST SUCCESS\n");
		
		
		System.out.println("\n==================== END Third Partition ====================\n");
	}
	
	@Test
	public void testRandom() 
	{

		System.out.println("\n==================== Random Test ====================\n");
		
		int iterations = 100, errorCount = 0;
		
		String[] validSchemes = { "http://", "ftp://", "h3t://", "" };
		String[] validAuths = { "www.google.com", "facebook.com", "github.com", "0.0.0.0", "255.255.255.255"};
		String[] validPorts = { ":80", ":65535", ":0", "" };
		String[] validPaths = { "/example", "/abc", "/$99", "/ex/", "", "/ex1/file" };
		String[] validQueries = { "?action=view", "?action=edit&mode=up", "" };

		// to store failed URL
		String[] badUrl = new String[iterations];
		int failIndex = 0;

		for (int i = 0; i < iterations; i++) 
		{
			UrlValidator validator = new UrlValidator();
			
			int randScheme = (int) (Math.random() * 3);
			int randAuth = (int) (Math.random() * 4);
			int randPort = (int) (Math.random() * 3);
			int randPath = (int) (Math.random() * 5);
			int randQuer = (int) (Math.random() * 2);

			
			String test_url = validSchemes[randScheme] + validAuths[randAuth] + validPorts[randPort] + validPaths[randPath] + validQueries[randQuer];

			
			// check the generated URL
			boolean isValid = validator.isValid(test_url);

			if (isValid == false) 
			{
				errorCount++;
				badUrl[failIndex] = test_url;
				failIndex++;
			} 
			else 
			{
				System.out.println("NO ERROR: "+test_url);
			}
		}

		System.out.println("Total Error Count: " + errorCount + "\n");
		System.out.println("Failed URLs: \n");
		
		for (int i = 0; i < badUrl.length; i++) 
		{
			if (badUrl[i] != null) 
			{
				System.out.println(badUrl[i] + "\n");
			} 
		}
	}
}