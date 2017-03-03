
import UIKit
import Foundation
import CoreLocation

class ViewController: UIViewController, CLLocationManagerDelegate {
    private var locationMgr: CLLocationManager?

    func locationManager(manager: CLLocationManager!, didUpdateLocations locations: [AnyObject]!) {
        let location = locations.last as CLLocation
        let geocoder = CLGeocoder()

        geocoder.reverseGeocodeLocation(location, completionHandler: { (placemarks, error) in
            if placemarks == nil {
                return
            }

            let placemark = placemarks.last as? CLPlacemark
            let privance = placemark?.administrativeArea
            let city = placemark?.locality
            let town = placemark?.subLocality
            let address = "\(privance!)-\(city!)-\(town!)"
            self.region = address

            self.locationMgr?.stopUpdatingLocation()
        })
    }

    func locationManager(manager: CLLocationManager!, didUpdateToLocation newLocation: CLLocation!, fromLocation oldLocation: CLLocation!) {
        //println("update to new location")
    }

    func locationManager(manager: CLLocationManager!, didFailWithError error: NSError!) {
        println("error \(error)")
    }

    func startMonitorLocation() {
        if locationMgr == nil {
            let manager = CLLocationManager()
            manager.delegate = self
            manager.desiredAccuracy = kCLLocationAccuracyHundredMeters

            if manager.respondsToSelector(Selector("requestAlwaysAuthorization")) {
                manager.requestAlwaysAuthorization()
            }
            manager.startUpdatingLocation()
            locationMgr = manager
        }
    }
}

