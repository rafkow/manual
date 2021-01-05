DateTime time_delta = new DateTime();


switch(cycle) {
				case "Shift":
					if(DateTime.Now.Hour<7) time_delta=DateTime.Today.AddHours(-5);
					else if(DateTime.Now.Hour<19) time_delta=DateTime.Today.AddHours(7);
					else time_delta=DateTime.Today.AddHours(19);
					break;
				case "Day":
					time_delta=DateTime.Today.AddDays(-1);
					break;
				case "Week":
					time_delta=DateTime.Today.AddDays(-(int)DateTime.Today.DayOfWeek);
					break;
				case "Bi Week":
					time_delta=DateTime.Today.AddDays(-(int)DateTime.Today.DayOfWeek);
					break;
				case "Month":
					time_delta=DateTime.Today.AddDays(-(int)DateTime.Today.Day+1);
					break;
				default:
					time_delta=new DateTime();
          break;

			}
