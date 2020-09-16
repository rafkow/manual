using Rotativa;
PM> Install-Package Rotativa -Version

[System.Web.Mvc.HttpPost]
public ActionResult CourseDocument([FromBody] CourseOrder course) {
    return new ActionAsPdf("PrintDocument", course) { FileName="Szkolenie.pdf" };
}

public ActionResult PrintDocument(CourseOrder course) {
            ManageCourses manage = new ManageCourses();
            PrintModel model = new PrintModel {
                Course=manage.GetSelectedCourse(course.course_id),
                Members=manage.GetCourseOrderList().Where(c => c.StatusCode==1&
                c.course_id==course.course_id&
                DateTime.Compare(c.EventDate, course.EventDate)==0)
            };
            model.Members.First().Substantiation=course.Substantiation;
            return View("PrintDocument", model);
        }
