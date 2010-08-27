// $Id$

Drupal.behaviors.fullcalendar = function(context) {
  $('.external-events div.external-event').each(function() {
    
    // create an Event Object (http://arshaw.com/fullcalendar/docs/event_data/Event_Object/)
    // it doesn't need to have a start or end
    var eventObject = {
      title: $.trim($(this).text()) // use the element's text as the event title
    };
                                                    
    // store the Event Object in the DOM element so we can get to it later
    $(this).data('eventObject', eventObject);
                                                                      
    // make the event draggable using jQuery UI
    $(this).draggable({
      zIndex: 999,
      revert: true,      // will cause the event to go back to its
      revertDuration: 0  //  original position after the drag
    });
  });

  var calendar = $('.fullcalendar:not(.fullcalendar-rendered)').fullCalendar({
    header: {
      left: 'prev,next today',
      center: 'title',
      right: 'month,agendaWeek,agendaDay'
    },
    editable: true,
    droppable: true, // this allows things to be dropped onto the calendar !!!
    drop: function(date, allDay) { // this function is called when something is dropped
                      
      // retrieve the dropped element's stored Event Object
      var originalEventObject = $(this).data('eventObject');
                                              
      // we need to copy it, so that multiple events don't have a reference to the same object
      var copiedEventObject = $.extend({}, originalEventObject);
                                                                      
      // assign it the date that was reported
      copiedEventObject.start = date;
      copiedEventObject.allDay = allDay;
                                                                                                      
      // render the event on the calendar
      // the last `true` argument determines if the event "sticks" (http://arshaw.com/fullcalendar/docs/event_rendering/renderEvent/)
      calendar.fullCalendar('renderEvent', copiedEventObject, true);
     
      $(this).remove();
    },
    selectable: true,
    selectHelper: true,
    select: function(start, end, allDay) {
      var title = prompt('Event Title:');
      if (title) {
        calendar.fullCalendar('renderEvent',
          {
          title: title,
          start: start,
          end: end,
          allDay: allDay
          },
          true // make the event "stick"
        );
      }
      calendar.fullCalendar('unselect');
    },
/*
    eventRender: function(event, element) {
      element.qtip({
        content: event.description
      });
    },
*/
    events: [
      {
        title: 'My Event',
        start: new Date(2010,08,26),
        description: 'This is a cool event'
      }
      // more events here
    ],

  }).addClass('fullcalendar-rendered');
}


