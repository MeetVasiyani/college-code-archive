using Microsoft.AspNetCore.Mvc;

namespace Hospital_Management_System.Controllers
{
    public class Patient : Controller
    {
        // GET: Patient
        public IActionResult Index()
        {
            return View();
        }
        public IActionResult PatientAddEdit()
        {
            return View();
        }
    }
}
