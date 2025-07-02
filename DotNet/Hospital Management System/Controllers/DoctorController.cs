using Microsoft.AspNetCore.Mvc;

namespace Hospital_Management_System.Controllers
{
    public class DoctorController : Controller
    {
        // GET: DoctorController
        public IActionResult Index() { 
            return View();
        }
        public IActionResult DoctorAddEdit()
        {
            return View();
        }

    }
}