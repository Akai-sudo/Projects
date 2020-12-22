import java.time.LocalDate;
import java.time.YearMonth;
import java.util.Scanner;

public class yourAgeInDays {

	private static int getDaysFromMonth(int year1, int year2, int month1, int month2) {
		int numOfDays = 0;
		YearMonth mesecVLetu;
		while(year1 <= year2) {
			if(month1 > 12) {
				year1++;
				month1 = 1;
			}
			if(year1 == year2 && month1 == month2) {
				break;
			}
			mesecVLetu = YearMonth.of(year1, month1);
			numOfDays += mesecVLetu.lengthOfMonth();
			month1++;
		}
		return numOfDays;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Write your birth date in DD MM YYYY format: ");

		int day = sc.nextInt();
		int month = sc.nextInt();
		int year = sc.nextInt();

		long inDays;

		LocalDate today = LocalDate.now();
		int currentMonth = today.getMonthValue();
		int currentDay = today.getDayOfMonth();
		int currentYear = today.getYear();

		inDays = getDaysFromMonth(year, currentYear, month, currentMonth) + currentDay;
		inDays -= day;

		System.out.printf("You are %d days old today.\n", inDays);
		
	}
}